// https://leetcode-cn.com/problems/number-of-longest-increasing-subsequence/
/**
 给定一个未排序的整数数组，找到最长递增子序列的个数。

示例 1:

输入: [1,3,5,4,7]
输出: 2
解释: 有两个最长递增子序列，分别是 [1, 3, 4, 7] 和[1, 3, 5, 7]。
示例 2:

输入: [2,2,2,2,2]
输出: 5
解释: 最长递增子序列的长度是1，并且存在5个子序列的长度为1，因此输出5。
注意: 给定的数组长度不超过 2000 并且结果一定是32位有符号整数。
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
// 最长递增子序列个数
int findNumberOfLIS(vector<int> &nums)
{
    vector<int> vLengths(nums.size(), 1); // vLengths[i]记录以nums[i]为最后一个元素的最长递增序列长度
    vector<int> vCounts(nums.size(), 1);  // vCounts[i]记录vLengths[i]长度的递增序列对应数量
    if(nums.size() <= 0)
        return 0;
    int iMaxLen = 1;
    int iMaxNum = 0;
    for(size_t index = 1; index < nums.size(); index++)
    {
        for(size_t j = 0; j < index; j++)
        {
            if(nums[index] > nums[j] )
            {
                if(vLengths[index] < vLengths[j] + 1)
                {
                    vLengths[index] = vLengths[j] + 1;
                    vCounts[index] = vCounts[j];
                }
                else if(vLengths[index] == vLengths[j] + 1)
                {
                    vCounts[index] += vCounts[j];
                } 
                iMaxLen = iMaxLen > vLengths[index] ? iMaxLen : vLengths[index];
            }
        }
    }
    /*
    for(size_t index = 0; index < vLengths.size(); index++)
    {
       cout << vLengths[index] << ",";
    }
    cout << endl;
    for(size_t index = 0; index < vCounts.size(); index++)
    {
       cout << vCounts[index] << ",";
    }
    cout << "maxlen:" << iMaxLen << endl;
    */
    for(size_t index = 0; index < vLengths.size(); index++)
    {
        if(vLengths[index] == iMaxLen)
        {
            iMaxNum += vCounts[index];
        }
    } 
    return iMaxNum;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    cout << findNumberOfLIS(vInt) << endl;
    system("pause");
    return 0;
}