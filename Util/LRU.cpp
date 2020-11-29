#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
#include <time.h>
using namespace std;

class LRUCache
{
    public:
        LRUCache(int capatiy) { m_capatiy = capatiy; m_size = 0;}
        LRUCache() { m_capatiy = 10; m_size = 0;}
        ~LRUCache() {}

        int get(int key)
        {
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                int value = mItr->second->second;
                m_list.erase(mItr->second);
                m_list.push_front(make_pair(key,value));
                m_map[key] = m_list.begin();
                return value;
            }
            return -1;
        }

        int set(int key,int value)
        {
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                m_list.erase(mItr->second);               
            }
            else
            {
                if(m_size >= m_capatiy)
                {
                    int back = m_list.back().first;
                    mItr = m_map.find(back);
                    if(mItr != m_map.end())
                    {
                        m_list.erase(mItr->second);
                        m_map.erase(mItr);
                        m_size--;
                    }
                }
                m_size++;
            }
            m_list.push_front(make_pair(key,value));
            m_map[key] = m_list.begin();
            return 0;
        }
        void print()
        {
            typeof(m_list.begin()) lItr = m_list.begin();
            for(; lItr != m_list.end() ;lItr++)
            {
                cout << "(" << lItr->first << "," << lItr->second << ")"; 

            }
            cout << "==== size:" << m_size << " ===" <<endl;
        }
    private:
        unordered_map<int,list<pair<int,int> >::iterator> m_map;
        list<pair<int,int> > m_list;
        int m_capatiy;
        int m_size;
};

struct Node
{
    int key;
    int value;
    Node *prev,*next;
    Node() {key = value = -1; prev = next = NULL;}
    Node(int k,int v) { key = k ; value = v ; prev = next = NULL;}
};

// 双向链表
class DoubleLinkList
{
    public:
        DoubleLinkList() {m_size = 0; pHead = pTail = NULL;}
        ~DoubleLinkList() 
        {
            while(pHead != NULL)
            {
                Node* n = pHead;
                pHead = pHead->next;
                delete n;
            }
        }
        int size()
        {
            return m_size;
        }
        void print()
        {
            Node* n = pHead;
            while(n != NULL)
            {
                cout << "(" << n->key << "," << n->value << ")";
                n = n->next;
            }
            cout << "=== size:" << m_size << "====" << endl;
        }
        Node* getTail()
        {
            return pTail;
        }
        Node* getHead()
        {
            return pHead;
        }
        Node* moveToHead(Node* n)
        {
            if(n != NULL && pHead != n)
            {
                Node* prev = n->prev;
                Node* next = n->next;
                if(pTail == n)
                {
                    pTail = prev;
                }
                if(prev != NULL)
                {
                    prev->next = next;
                }
                if(next != NULL)
                {
                    next->prev = prev;
                }
                n->next = pHead;
                n->prev = NULL;
                pHead->prev = n;
                pHead = n;
            }
            return pHead;
        }

        Node* erase(Node* n)
        {
            Node* prev = n->prev;
            Node* next = n->next;
            if(prev != NULL)
            {
                prev->next = next;
            }
            if(next != NULL)
            {
                next->prev = prev;
            }
            if(pHead == n)
            {
                pHead = next;
            }
            if(pTail == n)
            {
                pTail = prev;
            }
            delete n;
            m_size--;
            return next;
        }

        Node* PushFront(int key,int value)
        {
            Node* n = new Node(key,value);
            if(pHead == NULL)
            {
                pHead = n;
                pTail = n;
            }
            else
            {
                n->next = pHead;
                n->prev = NULL;
                pHead->prev = n;
                pHead = n;
            }
            m_size++;
            return pHead;
        }
    private:
        int m_size;
        Node* pHead,*pTail;
};

class LRUCacheV2
{
    public:
        LRUCacheV2() { m_capatiy = 10;}
        LRUCacheV2(int capatiy) { m_capatiy = capatiy;}
        ~LRUCacheV2() {}
        int get(int key)
        {
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                int value = mItr->second->value;
                m_list.moveToHead(mItr->second);
                //m_map[key] = m_list.getHead();
                return value;
            }
            return -1;
        }
        int set(int key,int value)
        {
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                mItr->second->value = value;
                m_list.moveToHead(mItr->second);
                //m_map[key] = m_list.getHead();
            }
            else
            {
                if(m_list.size() >= m_capatiy)
                {
                    Node* n = m_list.getTail();
                    if (n != NULL)
                    {
                        mItr = m_map.find(n->key);
                        mItr != m_map.end() ? m_map.erase(mItr) : mItr = m_map.end();
                        m_list.erase(n);
                    }
                }
                m_map[key] = m_list.PushFront(key,value);
            }
            return 0;
        }
        void print()
        {
            m_list.print();
        }
    private:
        unordered_map<int,Node*> m_map;
        DoubleLinkList m_list;
        int m_capatiy;
};


template <typename K,typename V>
class LRUCacheV3
{
    public:
        LRUCacheV3(int capatiy) { m_capatiy = capatiy; m_size = 0;}
        LRUCacheV3() { m_capatiy = 10; m_size = 0;}
        ~LRUCacheV3() {}

        V get(K key)
        {
            V value;
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                value = mItr->second->second;
                m_list.erase(mItr->second);
                m_list.push_front(make_pair(key,value));
                m_map[key] = m_list.begin();
                return value;
            }
            //return value;
        }

        int set(K key,V value)
        {
            typeof(m_map.begin()) mItr = m_map.find(key);
            if(mItr != m_map.end())
            {
                m_list.erase(mItr->second);               
            }
            else
            {
                if(m_size >= m_capatiy)
                {
                    K back = m_list.back().first;
                    mItr = m_map.find(back);
                    if(mItr != m_map.end())
                    {
                        m_list.erase(mItr->second);
                        m_map.erase(mItr);
                        m_size--;
                    }
                }
                m_size++;
            }
            m_list.push_front(make_pair(key,value));
            m_map[key] = m_list.begin();
            return 0;
        }
       
        void print()
        {
            typeof(m_list.begin()) lItr = m_list.begin();
            for(; lItr != m_list.end() ;lItr++)
            {
                cout << "(" << lItr->first << "," << lItr->second << ")"; 

            }
            cout << "==== size:" << m_size << " ===" <<endl;
        }
        
    private:
        unordered_map<K,typename list<pair<K,V> >::iterator> m_map;
        list<pair<K,V> > m_list;
        int m_capatiy;
        int m_size;
};


class LRUCacheV4 {
public:
	LRUCacheV4(int capacity) : capacity(capacity) {}
	int get(int key) {
		if (pos.find(key) != pos.end()){
			put(key, pos[key]->second);
			return pos[key]->second;
		}
		return -1;
	}
	void put(int key, int value) {
		if (pos.find(key) != pos.end())
			recent.erase(pos[key]);
		else if (recent.size() >= capacity) {
			pos.erase(recent.back().first);
			recent.pop_back();
		}
		recent.push_front({ key, value });
		pos[key] = recent.begin();
	}
private:
	int capacity;
	list<pair<int, int>> recent;
	unordered_map<int, list<pair<int, int>>::iterator> pos;  //value存储的是一个迭代器
};

int main(int argc, char** argv) 
{    
    LRUCacheV3<int,int> c(2);
    c.set(2,1);
    c.print();
    c.set(2,2);
    c.print();
    c.get(2);
    c.print();
    c.set(1,1);
    c.print();
    c.set(4,1);
    c.print();
    c.get(2);
    c.print();
    cout << "---------" << endl;
    
    srand(time(0));

    int capacity = 5;
    int test_loop_times = 10;
    if (argc>1){
        capacity = atoi(argv[1]);
    }
    if (argc>2){
        test_loop_times = atoi(argv[1]);
    }

    LRUCacheV3<int,int> cache(capacity);

    int v; 
    for(int i=0; i<test_loop_times; i++) {
        v = i;//rand() % capacity;
        
        cout << "set " << v << ": ";
        cache.set(v, v);
        cache.print();

        v = rand() % capacity;
        cout << "get " << v << ": " << cache.get(v);
        cache.print();

        cout << endl;
    }
    system("pause");
    return 0;
}