#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
struct BTree
{
    BTree *left;
    BTree *right;
    int iData;
    BTree(int value)
    {
        left = right = NULL;
        iData = value;
    }
};

void InsertToBT(BTree *&root, int value)
{
    BTree *node = new BTree(value);
    if (root == NULL)
    {
        root = node;
        return;
    }
    BTree *find = root;
    while (find != NULL)
    {
        if (find->iData >= value)
        {
            if (find->left == NULL)
                break;
            else
                find = find->left;
        }
        else
        {
            if (find->right == NULL)
                break;
            else
                find = find->right;
        }
    }
    if (find != NULL && find->iData >= value && find->left == NULL)
    {
        find->left = node;
    }
    else if (find != NULL && find->iData < value && find->right == NULL)
    {
        find->right = node;
    }
}


void helper(BTree* root, BTree*& pHead, BTree*& pTail)
{
    if(root == NULL || (root->left == NULL && root->right == NULL))
    {
        pHead = root;
        pTail = root;
    }
    else
    {
        BTree* pLHead = NULL;
        BTree* pLTail = NULL;
        BTree* pRHead = NULL;
        BTree* pRTail = NULL;
        helper(root->left, pLHead, pLTail);
        helper(root->right, pRHead, pRTail);
        if(pRHead != NULL)
        {
            root->right = pRHead;
            pRHead->left = root;
            pTail = pRTail;
        }
        else
        {
            root->left = NULL;
            root->right = NULL;
            pTail = root;
        }
        
        if(pLHead != NULL)
        {
            pLTail->right = root;
            root->left = pLTail;
            pHead = pLHead;
        }
        else
        {
            root->left = NULL;
            pHead = root;
        }
    }
}


BTree* ConvertToList(BTree* pRootOfTree)
{
    BTree* pHead = NULL;
    BTree* pTail = NULL;
    
    if(pRootOfTree == NULL)
        return NULL;
    helper(pRootOfTree, pHead, pTail);
    return pHead;
}

int main()
{
    BTree *root = NULL;
    InsertToBT(root, 100);
    InsertToBT(root, 40);
    InsertToBT(root, 120);
    InsertToBT(root, 20);
    InsertToBT(root, 60);
    InsertToBT(root, 110);
    InsertToBT(root, 50);
    InsertToBT(root, 45);
    InsertToBT(root, 55);
    InsertToBT(root, 42);
    InsertToBT(root, 48);
    InsertToBT(root, 53);
    InsertToBT(root, 41);
    InsertToBT(root, 47);
    InsertToBT(root, 46);
    BTree * tmp = ConvertToList(root);
    while(tmp != NULL)
    {
        cout << tmp->iData << ",";
        tmp = tmp->right;
    }
    system("pause");
    return 0;
}