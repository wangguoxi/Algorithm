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
 * K个有序链表合并
 */

List* MergeKList(vector<List*>& vList)
{
    List* root = NULL;
    List* tmp = NULL;
    while(vList.size())
    {
        // 每次都找数组中所有链表最小的节点
        vector<List*>::iterator vItr,vTmp;
        List* min = NULL;
        for(vItr = vList.begin() ; vItr != vList.end() ;)
        {
            if((*vItr) == NULL)
            {
                vItr = vList.erase(vItr);
                min = NULL;
                continue;
            }
            if(min == NULL || min->iData > (*vItr)->iData)
            {
                min = (*vItr);
                vTmp = vItr;
            }
            vItr++;
        }
        // 合并
        if(min != NULL)
        {
            *vTmp = min->next;
            min->next = NULL;
            if(tmp == NULL)
            {   
                tmp = min;
                root = min;
            }
            else
            {
                tmp->next = min;
                tmp = min;
            }  
        }
    }
    return root;
}


int main()
{
   
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
    vector<List*> vList;
    vList.push_back(first);
    vList.push_back(second);
    vList.push_back(third);
    vList.push_back(forth);
    MergeKList(vList);
  
    print(first);
    system("pause");
    return 0;
}