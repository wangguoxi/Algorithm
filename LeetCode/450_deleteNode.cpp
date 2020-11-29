// https://leetcode-cn.com/problems/delete-node-in-a-bst/
/**
 
 给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
说明： 要求算法时间复杂度为 O(h)，h 为树的高度。

示例:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。

一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。

    5
   / \
  4   6
 /     \
2       7

另一个正确答案是 [5,2,6,null,4,null,7]。

    5
   / \
  2   6
   \   \
    4   7
 */
#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int value)
    {
        left = right = NULL;
        val = value;
    }
};

void InsertToBT(TreeNode *&root, int value)
{
    TreeNode *node = new TreeNode(value);
    if (root == NULL)
    {
        root = node;
        return;
    }
    TreeNode *find = root;
    while (find != NULL)
    {
        if (find->val >= value)
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
    if (find != NULL && find->val >= value && find->left == NULL)
    {
        find->left = node;
    }
    else if (find != NULL && find->val < value && find->right == NULL)
    {
        find->right = node;
    }
}

void Print(TreeNode* root)
{
    deque<TreeNode*> de;
    if(root == NULL)
        return;
    de.push_back(root);
    while(!de.empty())
    {
        TreeNode* tmp = de.front();
        cout << tmp->val << ",";
        de.pop_front();
        if(tmp->left != NULL)
            de.push_back(tmp->left);
        if(tmp->right != NULL)
            de.push_back(tmp->right);
    }
    cout << endl;
}

// 先找再删除,边界的处理需要考虑
TreeNode *deleteNode(TreeNode *root, int key)
{
    TreeNode* cur = root; // 带删除的节点
    TreeNode* curParent = NULL; // 待删除的节点的父节点
    while(cur != NULL)
    {
        if(cur->val == key)
        {
            break;
        }
        else if(cur->val > key)
        {
            curParent = cur;
            cur = cur->left;
        }
        else
        {
            curParent = cur;
            cur = cur->right;
        } 
    }
    if(cur == NULL)
        return root;
    
    // 1、从当前待删除节点的右子树中找到最小的节点
    // 2、从当前待删除节点的左子树中找到最大的节点
    // 3、该节点为叶子节点，处理待删除节点的父节点
    if(cur->right != NULL)
    {
        TreeNode* minNode = cur->right;
        TreeNode* minNodeParent = cur;
        while (minNode != NULL && minNode->left != NULL)
        {
            minNodeParent = minNode;
            minNode = minNode->left;
        }
        cur->val = minNode->val;
        // 注意
        minNodeParent == cur ? cur->right = minNode->right : minNodeParent->left = minNode->right;
    }
    else if(cur->left != NULL)
    {
        TreeNode* maxNode = cur->left;
        TreeNode* maxNodeParent = cur;
        while(maxNode != NULL && maxNode->right != NULL)
        {
            maxNodeParent = maxNode;
            maxNode = maxNode->right;
        }
        cur->val = maxNode->val;
        // 注意
        maxNodeParent == cur ? cur->left = maxNode->left : maxNodeParent->right = maxNode->left;
    }
    else
    {
        if(cur == root)
            root = NULL;
        else
        {
            if(curParent->left == cur)
            {
                curParent->left = NULL;
            }
            else
            {
                curParent->right = NULL;
            }
        }
    }
    return root;
}

int main()
{
    TreeNode *root = NULL;
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
    Print(root);
    Print(deleteNode(root, 100));
    system("pause");
    return 0;
}