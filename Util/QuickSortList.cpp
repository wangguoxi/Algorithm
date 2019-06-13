#include <iostream>
#include <list>
#include <vector>
using namespace std;

struct List
{
    int iData;
    List* next;
};

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
 * 链表快速排序
 * 1、 找到基值节点
 * 2、 进行移位
 */
void QuickSort(List* begin,List* end)
{
    // 使用第一个节点的值作为比较基础值,整个区间是左闭右开
    if(begin == NULL || begin->next == end)
    {
        return ;
    }
    int value = begin->iData;
    List* tmp = NULL;
    List* trans = begin;
    for(; trans != end ; trans = trans->next)
    {
        if(trans->iData < value)
        {
            tmp = tmp == NULL ? begin : tmp->next;
            swap(tmp->iData,trans->iData);
        }  
    }
   
    // 这里一定要控制
    if(tmp != NULL)
    {
        QuickSort(begin,tmp);
        if(tmp->next != NULL)
        {
            QuickSort(tmp->next,end);
        }
    } 
}

int main()
{ 
    List* first = NULL; 
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
    
    QuickSort(first,NULL);
   
    print(first);
    system("pause");
    return 0;
}