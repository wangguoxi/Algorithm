/**
 * 单链表奇数位置的节点是升序，偶数位置的节点是降序
 * O(n)时间复杂度重新排序为升序
 * 思路:
 * 遍历单链表,将单链表进行拆分,奇数节点是升序，遍历的时候正序拆分
 * 偶数节点是降序，拆分的时候反转，最后的结果就是升序。
 * 将两个升序链表合并
 */
#include <iostream>
#include <vector>
using namespace std;

struct List
{
    struct List* next;
    int value;
    List()
    {
        next = NULL;
        value = 0;
    }
    List(int _value)
    {
        next  = NULL;
        value = _value;
    }
};

void InsertList(List*& head, int value)
{
    List* tmp = new List(value);
    if(head == NULL)
    {
        head = tmp;
    }
    else
    {
        List* util = head;
        while(util->next != NULL)
            util = util->next;
        util->next = tmp;
    }
}

void ResetOrder(List*& head)
{
    if(head == NULL || head->next == NULL)
        return ;
    List* odd =  NULL; // 奇数
    List* oddHead = NULL;
    List* evenHead = NULL;
    int iNum = 1;
    List* tmp = head;
    while(tmp != NULL)
    {
        if(iNum %2) // 奇数
        {
            if(odd == NULL)
            {
                odd = tmp;
                oddHead = odd;
            }
            else
            {
                odd->next = tmp;
            }
            odd = tmp;
            tmp = tmp->next;
        }
        else
        {
            List* tmpNext = tmp->next;
            tmp->next = evenHead;
            evenHead = tmp;
            tmp = tmpNext;
        }
        iNum++;    
    }
    if(oddHead != NULL)
        odd->next = NULL;
    // 合并排序
    tmp = NULL;
    while(evenHead != NULL && oddHead != NULL)
    {
        if(oddHead->value < evenHead->value)
        {
            if(tmp == NULL)
            {
                head = oddHead;
            }
            else
            {  
                tmp->next = oddHead;
            }
            tmp = oddHead;
            oddHead = oddHead->next;
        }
        else
        {
            if(tmp == NULL)
            {
                head = evenHead;
            }
            else
            {
                tmp->next = evenHead;
            }
            tmp = evenHead;
            evenHead = evenHead->next;
        }
    }
    if(evenHead == NULL)
        tmp->next = oddHead;
    if(oddHead == NULL)
        tmp->next = evenHead;
}
// 把奇数节点和偶数节点拆分开
int main()
{
    List* head = NULL;
    // 奇数是升序 偶数是降序
    InsertList(head,-1);
    
    InsertList(head,90);
    
    InsertList(head,5);
    
    InsertList(head,0);
    
    InsertList(head,7);
    
    InsertList(head,-1);
    
    InsertList(head,9);

    InsertList(head,-2);
    
    ResetOrder(head);
    while(head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
    system("pause");
    return 0;
}