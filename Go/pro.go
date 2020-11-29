package main

import (
	"sync"
	"sync/atomic"
	"unsafe"
)

// Node 节点
type Node struct {
	Value interface{}
	Next  unsafe.Pointer
}

// LFQueue 无锁队列
type LFQueue struct {
	Head unsafe.Pointer
	Tail unsafe.Pointer
}

// InitLFQueue 初始化队列
func InitLFQueue() *LFQueue {
	node := &Node{}
	return &LFQueue{Head: unsafe.Pointer(node), Tail: unsafe.Pointer(node)}
}

// Enqueue 入队, 核心是处理队尾插入元素,队尾元素变化
func (Q *LFQueue) Enqueue(v interface{}) {
	node := &Node{Value: v, Next: nil}
	for {
		tail := (*Node)(Q.Tail) // &Node
		if CAS(&tail.Next, nil, node) {
			CAS(&Q.Tail, tail, node)
			break
		}
	}
}

// EnqueueV2 ...
func (Q *LFQueue) EnqueueV2(v interface{}) {
	node := &Node{Value: v, Next: nil}
	for {
		tail := (*Node)(Q.Tail) // &Node
		for {
			if tail.Next == nil {
				break
			}
			tail = (*Node)(tail.Next)
		}
		if CAS(&tail.Next, nil, node) {
			CAS(&Q.Tail, tail, node)
			break
		}
	}
}

// EnqueueV3 ...
func (Q *LFQueue) EnqueueV3(v interface{}) {
	node := &Node{Value: v, Next: nil}
	for {
		tail := (*Node)(Q.Tail) // &Node
		if tail != (*Node)(Q.Tail) {
			continue
		}
		if tail.Next != nil {
			CAS(&Q.Tail, tail, (*Node)(tail.Next))
			continue
		}
		if CAS(&tail.Next, nil, node) {
			CAS(&Q.Tail, tail, node)
			break
		}
	}
}

// Dequeue 出队
func (Q *LFQueue) Dequeue() interface{} {

	for {
		head := (*Node)(Q.Head)
		tail := (*Node)(Q.Tail)
		next := (*Node)(head.Next)
		if head != (*Node)(Q.Head) {
			continue
		}
		if head == tail && next == nil {
			return nil
		}
		if head == tail && next != nil {
			CAS(&Q.Tail, tail, next)
			continue
		}
		if CAS(&Q.Head, head, next) {
			return next.Value
		}
	}
}

// CAS ...
func CAS(old *unsafe.Pointer, cur, new *Node) bool {
	return atomic.CompareAndSwapPointer(old, unsafe.Pointer(cur), unsafe.Pointer(new))
}
func main() {
	Q := InitLFQueue()
	wg := new(sync.WaitGroup)
	for i := 0; i < 5; i++ {
		wg.Add(2)
		go func(i int) {
			defer wg.Done()
			for j := 0; j < 1000000; j++ {
				Q.EnqueueV3(i)
			}
		}(i)

		go func(i int) {
			defer wg.Done()
			for j := 0; j < 1000000; j++ {
				Q.Dequeue()
			}
		}(i)
	}
	wg.Wait()
}
