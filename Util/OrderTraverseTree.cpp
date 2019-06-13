#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
struct BTree
{
    BTree* left;
    BTree* right;
    int iData;
    BTree(int value)
    {
        left = right = NULL;
        iData = value;
    }
};

void InsertToBT(BTree*& root,int value)
{
    BTree* node = new BTree(value);
    if(root == NULL)
    {
        root = node;
        return ;
    }
    BTree* find = root;
    while(find != NULL)
    {
        if(find->iData >= value)
        {
            if(find->left == NULL)
                break;
            else
                find = find->left;            
        }
        else
        {
            if(find->right == NULL)
                break;
            else
                find = find->right;
        }  
    }
    if(find != NULL && find->iData >= value && find->left == NULL)
    {
        find->left = node;
    }
    else if(find != NULL && find->iData < value && find->right == NULL)
    {
        find->right = node;
    }
}

// 先序遍
void PreOrder(BTree* root)
{
    stack<BTree*> st;
    if(root == NULL)
        return ;
    BTree* tmp = root;
    while(!st.empty() || tmp != NULL)
    {
        // 先拿出来
        if(tmp != NULL)
        {
            cout << tmp->iData << endl;
            st.push(tmp);
            tmp = tmp->left;
        }
        else
        {
            tmp = st.top();
            st.pop();
            tmp = tmp->right;
        }
    } 
}

// 中序
void InOrder(BTree* root)
{
    stack<BTree*> st;
    if(root == NULL)
        return ;
    BTree* tmp = root;
    while(!st.empty() || tmp != NULL)
    {
        // 先拿出来
        if(tmp != NULL)
        {
            st.push(tmp);
            tmp = tmp->left;
        }
        else
        {
            tmp = st.top();
            cout << tmp->iData << endl;
            st.pop();
            tmp = tmp->right;
        }
    } 
}

// 後續
void PostOrder(BTree* root)
{
    stack<BTree*> st;
    if(root == NULL)
        return ;
    BTree* tmp = root;
    BTree* iLastVisit = NULL;
    while(!st.empty() || tmp != NULL)
    {
        // 先拿出来
        if(tmp != NULL)
        {
            st.push(tmp);
            tmp = tmp->left;
        }
        else
        {
            tmp = st.top();
            if(tmp->right == NULL || tmp->right == iLastVisit)
            {
                cout << tmp->iData << endl;
                iLastVisit = tmp;
                tmp = NULL;
                st.pop();

            }
            else
            {
                tmp = tmp->right;
            }   
        }
    } 
}

int main()
{
    BTree* root = NULL;
    InsertToBT(root,100);
    InsertToBT(root,40);
    InsertToBT(root,120);
    InsertToBT(root,20);
    InsertToBT(root,60);
    InsertToBT(root,110);
    InsertToBT(root,50);
    InsertToBT(root,45);
    InsertToBT(root,55);
    InsertToBT(root,42);
    InsertToBT(root,48);
    InsertToBT(root,53);
    InsertToBT(root,41);
    InsertToBT(root,47);
    InsertToBT(root,46);
   
    system("pause");
    return 0;
}