#include <iostream>
#include <list>
#include <vector>
using namespace std;
/**
 * 
 *  合并两个有序的链表
 */
int Merge2List(list<int>& lFirst,list<int>& lSecond,list<int>& lTarget)
{
    auto iFirst = lFirst.begin();
    auto iSecond = lSecond.begin();
    for(; iFirst != lFirst.end() && iSecond != lSecond.end() ;)
    {
        if((*iFirst) <= (*iSecond))
        {
            lTarget.push_back(*iFirst);
            iFirst++;
        }
        else
        {
            lTarget.push_back(*iSecond);
            iSecond++;
        }  
    }
    if(iFirst != lFirst.end())
    {
        for(; iFirst != lFirst.end() ; iFirst++)
        {
            lTarget.push_back(*iFirst);
        }
    }
    if(iSecond != lSecond.end())
    {
        for(; iSecond != lSecond.end() ; iSecond++)
        {
            lTarget.push_back(*iSecond);
        }
    }
    return 0;
}

// 数据合并到第一个链表内
void MergeList(list<int>& lFirst,list<int>& lSecond)
{
    auto iFirst = lFirst.begin();
    auto iSecond = lSecond.begin();
    for(; iFirst != lFirst.end() && iSecond != lSecond.end() ;)
    {
        if((*iFirst) >= (*iSecond))
        {
            lFirst.insert(iFirst,(*iSecond)); // STL链表的插入是插入当前节点前一个位置
            iSecond++;
        }
        else
        {
            iFirst++;
        }
    }
    while(iSecond != lSecond.end())
    {
        lFirst.push_back((*iSecond));
        iSecond++;
    }
    return ;
}

void print(list<int>& lList)
{
    for(auto itr = lList.begin() ; itr != lList.end() ; itr++)
    {
        cout << (*itr) << " ";
    }
    cout << endl;
}

struct List
{
    int iData;
    List* next;
};

void MergeList(List*& first,List*& second)
{
    List* itrF = first;
    List* itrS = second;
    if(first == NULL || second == NULL)
    {
        first = second != NULL ? second : NULL ;
        return ;
    }
    // first非空，合并处理
    if(first->iData > second->iData)
    {
        swap(first,second);
    }
    for(; itrF != NULL && itrS != NULL ;)
    {   
        List* tmp = itrS;
        if((itrF->next == NULL) || (itrF->next != NULL && itrF->next->iData >= itrS->iData))
        {
            itrS = itrS->next;    
            tmp->next = itrF->next;
            itrF->next = tmp;    
        }
        itrF = itrF->next;
    }
}

void PushFront(List*& root,int value)
{
    List* node = new List;
    node->next = NULL;
    node->iData = value;
    if(root == NULL)
    {
        root = node;
    }
    else
    {
        node->next = root;
        root = node;
    }
}

void print(List* root)
{
    if(root == NULL)
    {
        cout << endl;
        return ;
    }
    else
    {
        cout << root->iData << " ";
        print(root->next);    
    }   
}

/**
 * 链表归并排序
 */
void MergeSort(List* begin,List* end)
{
    if(begin == NULL || begin->next == end)
    {
        return ;
    }
    // 找到中间位置,分别归并, 然后合并
    List* slow = begin;
    List* fast = begin;
    while(fast != NULL && fast != end)
    {
        fast = fast->next;
        if(fast != NULL && fast != end)
        {
            slow = slow->next;
            fast = fast->next;    
        }
    }
    // slow是中间位置
    MergeSort(begin,slow);
    MergeSort(slow,end);
    // 合并两个有序链表 [begin,slow) [slow,end)
    List* tmp = begin;
    List* tmp1 = slow;
    while(tmp != NULL && tmp != tmp1 && tmp1 != end)
    {
        // 开始追赶置换,原地置换
        if(tmp->iData<= tmp1->iData)
        {
            tmp = tmp->next;
        }  
        else
        {
            swap(tmp->iData,tmp1->iData);
            tmp = tmp->next;
            // 从当前位置全部置换,然后后半部分的指针移动一个位置
            List* tmp2 = tmp;
            for(; tmp2 != tmp1;)
            {
                swap(tmp2->iData,tmp1->iData);
                tmp2 = tmp2->next;
            }
            tmp1 = tmp1->next;
        }    
    }
}


int main()
{
    /*
    list<int> lFirst;
    list<int> lSecond;
    lFirst.push_back(3);
    lFirst.push_back(5);
    lFirst.push_back(7);
    lFirst.push_back(9);
    lFirst.push_back(14);
    lFirst.push_back(33);
    lFirst.push_back(3434);
    
    lSecond.push_back(1);
    lSecond.push_back(5);
    lSecond.push_back(7);
    lSecond.push_back(9);
    lSecond.push_back(12);
    lSecond.push_back(23);
    lSecond.push_back(78);
    lSecond.push_back(99);
    lSecond.push_back(400);
    lSecond.push_back(1234);
    lSecond.push_back(4123);
    print(lFirst);
    print(lSecond);
    MergeList(lFirst,lSecond);
    print(lFirst);
    */
    List* first = NULL;
    List* second = NULL;
    List* third = NULL;
    List* forth = NULL;
    PushFront(first,4123);
    PushFront(first,4123);
    PushFront(first,1234);
   
    PushFront(first,12);
    PushFront(first,9);
    PushFront(first,7);
     PushFront(first,400);
    PushFront(first,99);
    PushFront(first,78);
    PushFront(first,23);
    PushFront(first,5);
    PushFront(first,1);
    PushFront(first,12);
    PushFront(first,12);
    PushFront(first,12);

    PushFront(second,3434);
    PushFront(second,33);
    PushFront(second,14);
    PushFront(second,9);
    PushFront(second,7);
    PushFront(second,5);
    PushFront(second,0);

    PushFront(third,90);
    PushFront(third,70);
    PushFront(third,50);
    PushFront(third,10);

    PushFront(forth,99);
    PushFront(forth,79);
    PushFront(forth,59);
    PushFront(forth,19);
    PushFront(forth,50);
/*
    print(first);
    print(second);
    vector<List*> vList;
    vList.push_back(first);
    vList.push_back(second);
    vList.push_back(third);
    vList.push_back(forth);
    MergeKList(vList);
    //MergeList(first,second);
    print(first);
    //TransferList(first);
    print(first);
    */
    //QuickSort(first,NULL);
    MergeSort(first,NULL);
    print(first);
    system("pause");
    return 0;
}