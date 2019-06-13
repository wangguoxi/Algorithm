// https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence/
/**
 给定一个未经排序的整数数组，找到最长且连续的的递增序列。

示例 1:

输入: [1,3,5,4,7]
输出: 3
解释: 最长连续递增序列是 [1,3,5], 长度为3。
尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。 
示例 2:

输入: [2,2,2,2,2]
输出: 1
解释: 最长连续递增序列是 [2], 长度为1。
注意：数组长度不会超过10000。
 */
#include <iostream>
#include <vector>

using namespace std;

int findLengthOfLCIS(vector<int> &nums)
{
    vector<int> vFlag(nums.size(), 1);
    if(nums.size() <= 0)
        return 0;
    int iMaxLen = 1;
    for(size_t index = 1; index < nums.size(); index++)
    {
        if(nums[index] > nums[index -1])
        {
            vFlag[index] = vFlag[index] > vFlag[index-1] + 1 ? vFlag[index] : vFlag[index-1] + 1;
            iMaxLen = iMaxLen > vFlag[index] ? iMaxLen : vFlag[index];
        }
    }
    return iMaxLen;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(5);
    vInt.push_back(4);
    vInt.push_back(7);
    cout << findLengthOfLCIS(vInt) << endl;
    system("pause");
    return 0;
}