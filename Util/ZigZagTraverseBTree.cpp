#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <list>
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

// 搜索二叉树插入
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

/**
 * 二叉树的锯齿形的层次遍历,给出一棵二叉树，
 * 返回其节点值的锯齿形层次遍历(先从左往右，下一层再从右往左，层与层之间交替进行)
 * 先使用队列和栈来处理
 */
void ZigZagTraverseV1(BTree *root, vector<vector<int>> &vResult)
{
    if (root == NULL)
        return;
    int iLevel = 1;
    stack<BTree *> st;
    deque<BTree *> de;
    de.push_back(root);
    vector<int> vLevel;
    while (!st.empty() || !de.empty())
    {
        //偶数层,从堆栈中出来
        if (iLevel % 2 == 0)
        {
            if (st.empty())
            {
                iLevel++;
                vResult.push_back(vLevel);
                vLevel.clear();
            }
            else
            {
                BTree *node = st.top();
                vLevel.push_back(node->iData);
                st.pop();
                if (node->right != NULL)
                    de.push_front(node->right);
                if (node->left != NULL)
                    de.push_front(node->left);
            }
        }
        else // 奇数层次,从队列中出来
        {
            if (de.empty())
            {
                iLevel++;
                vResult.push_back(vLevel);
                vLevel.clear();
            }
            else
            {
                BTree *node = (*de.begin());
                de.pop_front();
                vLevel.push_back(node->iData);
                if (node->left != NULL)
                    st.push(node->left);
                if (node->right != NULL)
                    st.push(node->right);
            }
        }
    }
    vResult.push_back(vLevel);
}

/**
 * 使用双栈法
 */
void ZigZagTraverseV2(BTree *root, vector<vector<int>> &vResult)
{
    if (root == NULL)
        return;
    vector<int> vLevel;
    int iLevel = 1;
    stack<BTree *> first;
    stack<BTree *> second;
    first.push(root);
    while (!first.empty() || !second.empty())
    {
        // 奇数使用第一个栈, 从左到右遍历节点，出栈元素先左后右压入第二个栈
        if (iLevel % 2)
        {
            if (first.empty())
            {
                iLevel++;
                cout << endl;
            }
            else
            {
                BTree *node = first.top();
                first.pop();
                cout << node->iData << " ";
                if (node->left != NULL)
                    second.push(node->left);
                if (node->right != NULL)
                    second.push(node->right);
            }
        }
        else // 偶数使用第二个栈，从右到左遍历节点，出栈元素先右后左压入第一个栈
        {
            if (second.empty())
            {
                iLevel++;
                cout << endl;
            }
            else
            {
                BTree *node = second.top();
                second.pop();
                cout << node->iData << " ";
                if (node->right != NULL)
                    first.push(node->right);
                if (node->left != NULL)
                    first.push(node->left);
            }
        }
    }
}

/**
 * 使用一个队列来处理
 * 需要记录层数和当前层元素的个数
 * 奇数层从头开始出队列，出队列的元素使用先左后右的顺序压入队列尾部
 * 偶数层从尾开始出队列，出队列的元素使用先右后左的顺序压入队列的头部
 */
void ZigZagTraverseV3(BTree *root)
{
    deque<BTree *> de;
    int iLevel = 1;
    int iCurNum = 1;
    int iTmp = 0;
    if (root == NULL)
        return;
    de.push_back(root);
    while (!de.empty())
    {
        if (iLevel % 2)
        {
            BTree *node = (*de.begin());
            de.pop_front();
            cout << node->iData << " ";
            if (node->left != NULL)
            {
                de.push_back(node->left);
                iTmp++;
            }
            if (node->right != NULL)
            {
                de.push_back(node->right);
                iTmp++;
            }
        }
        else
        {
            BTree *node = (*de.rbegin());
            de.pop_back();
            cout << node->iData << " ";
            if (node->right != NULL)
            {
                de.push_front(node->right);
                iTmp++;
            }
            if (node->left != NULL)
            {
                de.push_front(node->left);
                iTmp++;
            }
        }
        iCurNum--;
        if (iCurNum == 0)
        {
            iLevel++;
            iCurNum = iTmp;
            iTmp = 0;
            cout << endl;
        }
    }
}

// 不使用临时变量实现之字型遍历
void ZigZagTraverseV4(BTree *root, list<BTree *> &lList)
{
    BTree *tmp = root;
    if (tmp == NULL)
        return;
    lList.push_back(tmp);
    int iPreLevelNum = 1;
    int iCurLevel = 1; // 奇数表示当前层次是从左到右边,偶数表示当前层次从右到左
    int iCurLevelNum = 0;
    list<BTree *>::reverse_iterator lItr = lList.rbegin();
    list<BTree *>::reverse_iterator lTmp;
    while (iPreLevelNum)
    {
        if (iCurLevel % 2)
        {
            if ((*lItr)->right != NULL)
            {
                lList.insert(lList.end(), (*lItr)->right);
                iCurLevelNum++;
                if(iCurLevelNum == 1 && lList.size() > 1)
                    lItr++;
            }
            if ((*lItr)->left != NULL)
            {
                lList.push_back((*lItr)->left);
                iCurLevelNum++;
                if(iCurLevelNum == 1 && lList.size() > 1)
                    lItr++;
            }
        }
        else
        {
            lTmp = lItr;
            if ((*lItr)->left != NULL)
            {
                lList.push_back((*lItr)->left);
                iCurLevelNum++;
                if(iCurLevelNum == 1 && lList.size() > 1)
                    lItr++;
            }
            if ((*lItr)->right != NULL)
            {
                lList.push_back((*lItr)->right);
                iCurLevelNum++;
                if(iCurLevelNum == 1 && lList.size() > 1)
                    lItr++;
            }
        }
        iPreLevelNum--;
        lItr++;
        if (iPreLevelNum == 0)
        {
            iPreLevelNum = iCurLevelNum;
            iCurLevelNum = 0;
            iCurLevel++;
            lItr = lList.rbegin();
        }
    }
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
    vector<vector<int>> vResult;
    ZigZagTraverseV1(root, vResult);
    for (int i = 0; i < vResult.size(); i++)
    {
        for (int j = 0; j < vResult[i].size(); j++)
        {
            cout << vResult[i][j] << ",";
        }
        cout << endl;
    }
    list<BTree *> lList;
    ZigZagTraverseV4(root, lList);
    cout << "size:" << lList.size() << endl;
    for (list<BTree *>::iterator lItr = lList.begin(); lItr != lList.end(); lItr++)
    {
        if ((*lItr) != NULL)
            cout << (*lItr)->iData << ",";
    }
    cout << endl;
    system("pause");
    return 0;
}