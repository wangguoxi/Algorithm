#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 一个未排序数组中最长连续序列的长度
 * 如果这里有可能是连续递增,有可能是连续递减，需要使用一个数组记录以当前节点为
 * 最后一个节点保留的最长连续序列
 */
struct NodeInfo {
    int same;   // 前面连续相同的节点个数
    int flag;   // 标记着当前节点保持最长连续的状态 升序/降序/单独节点
    int iMaxLen;// 以当前节点为尾的最长连续的序列长度
    NodeInfo()
    {
        same = 0;
        flag = 0; // 0单独节点,1 正递增, -1负递增
        iMaxLen = 1;
    }
};

int LongestMonotonousSeqV1(vector<int>& vInt)
{
    int iMaxLen = 0;
    vector<NodeInfo> vNodeInfo(vInt.size(),NodeInfo());
    for(size_t index = 1 ; index < vInt.size() ; index++)
    {
        // 查看前面相邻的元素是否可以构成最长连续序列
        if(vInt[index] > vInt[index-1])
        {
            vNodeInfo[index].flag = 1;
            vNodeInfo[index-1].flag >= 0 ? vNodeInfo[index].iMaxLen = vNodeInfo[index-1].iMaxLen + 1 :  vNodeInfo[index].iMaxLen = vNodeInfo[index].iMaxLen + 1;
            vNodeInfo[index-1].flag < 0? vNodeInfo[index].iMaxLen = vNodeInfo[index].iMaxLen + vNodeInfo[index-1].same: vNodeInfo[index].iMaxLen;

        }
        else if(vInt[index] < vInt[index-1])
        {
            vNodeInfo[index].flag = -1;
            vNodeInfo[index-1].flag <= 0 ? vNodeInfo[index].iMaxLen = vNodeInfo[index-1].iMaxLen + 1 : vNodeInfo[index].iMaxLen = vNodeInfo[index].iMaxLen + 1;
            vNodeInfo[index-1].flag > 0 ? vNodeInfo[index].iMaxLen = vNodeInfo[index].iMaxLen + vNodeInfo[index-1].same: vNodeInfo[index].iMaxLen;
        }
        else
        {
            vNodeInfo[index].same = vNodeInfo[index-1].same + 1;
            vNodeInfo[index].flag = vNodeInfo[index-1].flag;
            vNodeInfo[index].iMaxLen = vNodeInfo[index-1].iMaxLen + 1;
        }
        cout << vNodeInfo[index].same << " " << vNodeInfo[index].flag << " " << vNodeInfo[index].iMaxLen << endl;
        vNodeInfo[index].iMaxLen > iMaxLen ? iMaxLen = vNodeInfo[index].iMaxLen : iMaxLen;
    }
    return iMaxLen;
}

/**
 * 只需要记录上一个节点的情况即可
 */
int LongestMonotonousSeq(vector<int>& vInt)
{
    NodeInfo preNode;
    int iMaxLen = 0;
    int iMaxLenIndex = 0;
    for(size_t index = 0 ; index < vInt.size() ; index++)
    {
        if(index == 0)
        {
            iMaxLen  = 1;
            iMaxLenIndex = 0;
        }
        else
        {
            if(vInt[index] > vInt[index-1])
            {
                // 前面是升序
                preNode.flag >= 0 ? preNode.iMaxLen++ : preNode.iMaxLen = 2 + preNode.same;
                preNode.flag  = 1;
                preNode.same = 0;
            }
            else if(vInt[index] < vInt[index-1])
            {
                preNode.flag <= 0 ? preNode.iMaxLen++ : preNode.iMaxLen = 2 + preNode.same;    
                preNode.flag = -1;
                preNode.same = 0;
            }
            else
            {
                preNode.same++;
                preNode.iMaxLen++;
            }
            if(preNode.iMaxLen > iMaxLen)
            {
                iMaxLen = preNode.iMaxLen;
                iMaxLenIndex = index;
            }
        }
    }
    //cout << "maxlen:" << iMaxLen << ",maxindex:" << iMaxLenIndex << endl;
    return iMaxLen;
}




int main() 
{
    int array[] = {6,7,4,5,3,8,3,1,0};
   
    system("pause");
    return 0;
}