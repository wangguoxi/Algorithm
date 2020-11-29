/**
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <deque>
using namespace  std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {
	}
};

// 层次遍历二叉树
vector<int> PrintFromTopToBottom(TreeNode* root)
{
    deque<TreeNode*> de;
    vector<int> vInt;
    if(root != NULL)
        de.push_back(root);
    while(!de.empty())
    {
        TreeNode* tmp = de.front();
        de.pop_front();
        vInt.push_back(tmp->val);
        if(tmp->left != NULL)
            de.push_back(tmp->left);
        if(tmp->right != NULL)
            de.push_back(tmp->right);
    }
    return vInt;
}

int main()
{
    system("pause");
    return 0;
}