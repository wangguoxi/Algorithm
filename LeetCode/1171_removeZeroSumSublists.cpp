
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    };
    ListNode(int _val)
    {
        val = _val;
        next = NULL;
    }
};

void PushFront(ListNode *&head, int val)
{
    ListNode *tmp = new ListNode(val);
    if (head == NULL)
    {
        head = tmp;
    }
    else
    {
        tmp->next = head;
        head = tmp;
    }
}

void Print(ListNode* head)
{
    ListNode* tmp = head;
    while(tmp != NULL)
    {
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
}

/**
 * 
 * 记录前缀和,前缀和相等的区间和为0
 * 
 */
ListNode *removeZeroSumSublists(ListNode *head)
{
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode*> mMap;
    mMap[0] = dummy;
    int sum = 0;
    ListNode* tmp = dummy->next;
    while(tmp != NULL)
    {
        sum += tmp->val;
        if(mMap.find(sum) == mMap.end())
        {
            mMap[sum] = tmp;
            tmp = tmp->next;
        }
        else
        {
            ListNode* _tmp = mMap[sum]->next;
            int _sum = sum;
            while(_tmp  != tmp)
            {
                _sum += _tmp->val;
                mMap.erase(_sum);
                _tmp = _tmp->next;
            }
            mMap[sum]->next = tmp->next;
            tmp = tmp->next;
        }   
    }
    return dummy->next;
}

int main()
{
    // 1,2,-3,3,1
    ListNode* head = NULL;
    PushFront(head, 1);
    PushFront(head, 3);
    PushFront(head, -3);
    PushFront(head, 2);
    PushFront(head, 1);
    head = removeZeroSumSublists(head);
    cout << endl << endl;
    Print(head);
    system("pause");
    return 0;
}