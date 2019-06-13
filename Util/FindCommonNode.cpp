#include <iostream>
#include <vector>
#include <deque>
#include <stack>
using namespace std;

/**
 * 二叉树中任意三个节点的最近公共父节点 
 * 思路1：两两查找节点的公共父节点
 * 思路2：从根节点开始查找到该节点的路径，遍历三个路径，最后一个相同的节点就是公共父节点。(注意区分最后的节点可能是这三个节点中某一个)
 */

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

bool FindPath(BTree* root,int value,deque<int>& vPath)
{
    if(root == NULL)
    {
       // cout << "cur null" << endl;
        return false;
    }
    
    // 先压入路径记录
     bool bFind = false; 
    vPath.push_back(root->iData);
    //cout << "push_back:" << root->iData << endl;
    if(root->iData == value)
    {
        //cout << "find" << endl;
        bFind = true;
        return true;
    }
    
    if(!bFind && root->left != NULL)
    {
        bFind = FindPath(root->left,value,vPath);
    }
    if(!bFind && root->right != NULL)
    {
         bFind = FindPath(root->right,value,vPath);
    }
    if(!bFind)
       vPath.pop_back();
    return bFind;
}

bool CommonNode(BTree* root,int first,int second,int third, int& parent)
{
    deque<int> dPath1;
    deque<int> dPath2;
    deque<int> dPath3;
    bool bFirst = FindPath(root,first,dPath1);
    bool bSecond = FindPath(root,second,dPath2);
    bool bThird =  FindPath(root,third,dPath3);

    if(bFirst && bSecond && bThird)
    {
            parent = (*dPath1.begin());
            while(!dPath1.empty() && !dPath2.empty())
            {
                int val_first = (*dPath1.begin());
                int val_second = (*dPath2.begin());
                int val_third = (*dPath3.begin());
                if((val_first == val_second && val_second == val_third && val_first == val_third) || 
                 (val_first == first || val_first == second || val_first == third)
                 || (val_second == first || val_second == second || val_second == third)
                 || (val_third == first || val_third == second || val_third == third)
                )
                {
                    dPath1.pop_front();
                    dPath2.pop_front();
                    dPath3.pop_front();
                    if((val_first == val_second && val_second == val_third && val_first == val_third))
                    {
                        parent = val_first;
                    }
                    else if(val_first == first || val_first == second || val_first == third)
                    {
                        parent = val_first;
                    }
                    else if(val_second == first || val_second == second || val_second == third)
                    {
                        parent = val_second;
                    }
                    else if(val_third == first || val_third == second || val_third == third)
                    {
                        parent = val_third;
                    }
                }
                else
                {
                    break;
                }   
            }
            return true;
    }
    return false;
}


bool IsExists(BTree* root,int value)
{
    if(root == NULL)
        return false;
    else
    {
        if(root->iData == value)
            return true;
        else
            return (IsExists(root->left,value) || IsExists(root->right,value));
    }
}

BTree* helper(BTree* root,int first,int second)
{
    if(root == NULL 
        || (root->iData == first && IsExists(root,second)) 
        || (root->iData == second && IsExists(root,first)))
        return root;
    if(IsExists(root->left,first))
    {
        if(IsExists(root->right,second))
        {
            return root;
        }
        else
        {
            return helper(root->left,first,second);
        }    
    }
    else
    {
        return helper(root->right,first,second);
    }
}

BTree* CommonNodeV2(BTree* root,int first,int second,int third)
{
    BTree* tmp = helper(root, first, second);
    if(tmp != NULL)
    {
        int value = tmp->iData;
        tmp = helper(root, value, third);
        return tmp;
    }
    return NULL;
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
   
    int parent = 0;
    CommonNode(root,50,47,41,parent);
    BTree* tmp = CommonNodeV2(root,50,47,41);
    cout << parent << endl;
    if(tmp != NULL)
        cout << tmp->iData << endl;
    system("pause");
    return 0;
}