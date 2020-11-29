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

/**
 * 二叉树最近公共祖先
 * 1、当前节点和连个中一个相同，另外一个节点也在改节点为根的树中，当前节点就为最近公共
 * 2、一个节点在左子树，一个在右子树中，当前节点就是最近公共节点
 * 3、两个节点都在左/右子树，公共节点在左/右子树中查找
 */

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

BTree* CommonNode(BTree* root,int first,int second)
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
            return CommonNode(root->left,first,second);
        }    
    }
    else
    {
        return CommonNode(root->right,first,second);
    }
}

/**
 * 找到从根到当前节点的路径，路径中最后一个相同的节点就是最近公共祖先节点
 */
bool FindPath(BTree* root,int value,vector<int>& vPath)
{
    if(root == NULL)
    {
        return false;
    } 
    // 先压入路径记录
    vPath.push_back(root->iData);
    if(root->iData == value)
    {
        return true;
    }  
    bool bFind = FindPath(root->left,value,vPath);
    if(bFind == false)
    {
        bFind = FindPath(root->right,value,vPath);
        if(bFind == false)
        {
            vPath.pop_back();
        }
        else
        {
            return true;
        }  
    }
    else
    {
        return bFind;
    }
}

bool GetNodePath(BTree* pHead, int value, vector<int>& path)
{
    if(pHead == NULL)
        return false;
	path.push_back(pHead->iData); 
    bool found=false; 
    if(pHead->iData == value)
    {
        found = true;   
    }
	if(!found && pHead->left != NULL)
		found = GetNodePath(pHead->left, value, path);
	if(!found && pHead->right)
		found = GetNodePath(pHead->right, value, path);
	if(!found)
		path.pop_back();
	return found;
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
    vector<int> path;
    cout << GetNodePath(root, 45, path) << endl;
    for(int index = 0; index < path.size(); index++)
    {
        cout << path[index] << endl;
    }
    path.clear();

    cout << endl << FindPath(root, 45, path) << endl;
    for(int index = 0; index < path.size(); index++)
    {
        cout << path[index] << endl;
    }
    system("pause");
    return 0;
}