#include <iostream>
#include <vector>

using namespace std;

struct List {
    int value;
    struct List* next;
    List()
    {
        value = 0;
        next = NULL;
    };
    List(int _value)
    {
        value = _value;
        next = NULL;
    }
};

/*
    从头部插入节点
*/
void PushFront(List*& head, int value)
{
    List* tmp = new List(value);
    if(head == NULL)
    {
        head = tmp;
    }
    else 
    {
        tmp->next = head;
        head = tmp;
    }
}

/**
 * 对一个单链表重新排序，可以认为相当于围绕着链表节点绕环
 * 1->2->3->4->5->6    1->6->2->5->3->4  
 *  
 */

/**
 *  思路:链表的后半部分反转，前半部分和反转后的后半部分交叉逐次合并。
 */

List* ReorderList(List* head)
{
    // 找到中间节点
    if(head == NULL || head->next == NULL || head->next->next == NULL)
    {
        return head;
    }
    List* slow = head;
    List* fast = head->next;
    while(slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    
    // 反转后半部分 slow后面的节点开始反转
    List* tmp = slow->next;
    slow->next = NULL;
    fast = NULL;
    while(tmp != NULL)
    {
        slow = tmp->next;
        tmp->next = fast;
        fast = tmp;
        tmp = slow;
    }

    // 合并两个链表
    // fast 和 head 合并
    slow = head;
    int iCount = 1;
    while(slow != NULL && fast != NULL)
    {
        if(iCount %2 == 1) // slow -> fast
        {
            tmp = slow->next;
            slow->next = fast;
            slow = tmp;
        }
        else    // fast -> slow
        {
            tmp = fast->next;
            fast->next = slow;
            fast = tmp;
        }
        iCount++;
    }
    return head;
}

void Print(List* head)
{
    List* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->value << endl;
        tmp = tmp->next;
    }
}
int main()
{
    List* head = NULL;
    PushFront(head, 7);
    PushFront(head, 6);
    PushFront(head, 5);
    PushFront(head, 4);
    PushFront(head, 3);
    PushFront(head, 2);
    PushFront(head, 1);
    head = ReorderList(head);
    Print(head);
    system("pause");
    return 0;
}