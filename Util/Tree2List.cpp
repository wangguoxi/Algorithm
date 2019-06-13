#include <iostream>
#include <list>
#include <map>
#include <deque>
using namespace std;

struct BTree
{
    
    BTree* left;
    BTree* right;
    BTree* parent;
    BTree() 
    {
        left = right = parent = NULL;
        value = 0; 
    }
    BTree(int val)
    {
        left = right = parent = NULL;
        value = val;
    }
    int value;
};

int TreeDepth(BTree* root)
{
    if(root == NULL)
        return 0;
    return max(TreeDepth(root->left),TreeDepth(root->right)) + 1;
}
/**
 * 构造二叉搜索树
 * 
 */
void Insert2BST(BTree*& root,int value)
{
    BTree* pTmp = root;
    while(pTmp != NULL)
    {
        if(pTmp->value >= value)
        {
            if(pTmp->left == NULL)
            {
                break;
            }
            pTmp = pTmp->left;
        }
        else
        {
            if(pTmp->right == NULL)
            {
                break;
            }
            pTmp = pTmp->right;
        }
    }
    // 构造节点 && 插入节点
    BTree* node  = new BTree(value);
    if(pTmp == NULL)
    {
        root = node;
    }
    else
    {
        if(pTmp->value >= value)
        {
            pTmp->left = node;
        }
        else
        {
            pTmp->right = node;
        }
        node->parent = pTmp;
    }
    
}

/**
 * 二叉树按照层次遍历的顺序变成链表
 * 如果处理当前层次的非最后一个节点,那么就是当前层次该节点后面的节点
 * 如果处理当前层次的最后一个节点,那么需要连接的就是下一个层次中的第一个节点
 * 需要记录下一个层次的第一个节点,当前节点所在层次的个数(下一层节点个数和当前层节点个数)
 */
void BSTree2List(BTree* root,list<BTree*>& pList)
{
    BTree* pCurNode = root;
    BTree* pNextLevelFirst = NULL;
    int iCurLevelNum = root == NULL ?  0 : 1;
    int iNextLevelNum = 0;
    while(pCurNode != NULL && iCurLevelNum)
    {
        // 根据当前节点计算下一层节点个数
        iNextLevelNum = pCurNode->left != NULL ? iNextLevelNum + 1: iNextLevelNum;
        iNextLevelNum = pCurNode->right != NULL ? iNextLevelNum +1 : iNextLevelNum;
        // 判断下一层第一个节点
        if(pNextLevelFirst == NULL && pCurNode->left != NULL)
        {
            pNextLevelFirst = pCurNode->left;
        }
        if(pNextLevelFirst == NULL && pCurNode->right != NULL)
        {
            pNextLevelFirst = pCurNode->right;
        }
        pList.push_back(pCurNode);
        if(iCurLevelNum > 1)  // 当前节点不是该层最后节点,下一个节点是也在改层
        {
            iCurLevelNum--;
            if(pCurNode == pCurNode->parent->left && pCurNode->parent->right != NULL) // 是左节点
            {
                pCurNode = pCurNode->parent->right;
                continue;
            }
            // 从pList中超找后续的节点
            list<BTree*>::iterator lItr;
            for(lItr = pList.begin();lItr != pList.end() ; lItr++)
            {
                if((*lItr) == pCurNode->parent) // 找父节点下面的节点
                {
                    lItr++;
                    break;
                }
            }
            for(; lItr != pList.end(); lItr++)
            {
                if((*lItr)->left != NULL || (*lItr)->right != NULL)
                {
                    break;
                }
            }
            if(lItr != pList.end() && (*lItr)->left != NULL)
            {
                pCurNode = (*lItr)->left;
                continue;
            }
            else if(lItr != pList.end() && (*lItr)->right != NULL)
            {
                pCurNode = (*lItr)->right;
                continue;
            }
            else
            {
                pCurNode = NULL;
            }
        }
        else
        {
            pCurNode = pNextLevelFirst;
            pNextLevelFirst = NULL;
            iCurLevelNum = iNextLevelNum;
            iNextLevelNum = 0;
        }
    }
}

#if 1
/**
 * 非递归方式计算二叉树深度
 */
int TreeDepthV2(BTree* root)
{
    deque<BTree*> pDeque;
    int iCurrLevelNum = root == NULL ? 0 :1;
    int iNextLevelNum = 0;
    int iDepth = 0;
    if(root != NULL)
        pDeque.push_back(root);
    while (!pDeque.empty() && iCurrLevelNum)
    {
        BTree* pTmp = pDeque.front();
        pDeque.pop_front();
        iCurrLevelNum--;
        if(pTmp->left != NULL)
        {
            iNextLevelNum++;
            pDeque.push_back(pTmp->left);
        }
        if(pTmp->right != NULL)
        {
            iNextLevelNum++;
            pDeque.push_back(pTmp->right);
        }
        if(iCurrLevelNum == 0)
        {
            iCurrLevelNum = iNextLevelNum;
            iNextLevelNum = 0;
            iDepth++;
        }
    }
    return iDepth;
}
#endif
int main()
{
    BTree* root = NULL;
    list<BTree*> pList;
    Insert2BST(root,100);
    Insert2BST(root,80);
    Insert2BST(root,120);
    Insert2BST(root,60);
    Insert2BST(root,85);
    Insert2BST(root,110);
    Insert2BST(root,130);
    Insert2BST(root,82);
    Insert2BST(root,101);
    Insert2BST(root,140);
    Insert2BST(root,104);
    Insert2BST(root,105);
    Insert2BST(root,103);
    Insert2BST(root,102);
    Insert2BST(root,106);
    BSTree2List(root,pList);
    cout << TreeDepth(root) << ","  << TreeDepthV2(root) << endl;
    for(list<BTree*>::iterator lItr = pList.begin(); lItr != pList.end() ; lItr++)
    {
        cout << (*lItr)->value << endl;
    }
    system("pause");
    return 0;
}