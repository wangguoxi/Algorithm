/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int subarraySum(vector<int> &nums, int k)
{
    int iCount = 0;
    vector<int> vSubSum;
    int iSum = 0;
    for(size_t index = 0; index < nums.size(); index++)
    {
        iSum += nums[index];
        vSubSum.push_back(iSum);
    }
    for(size_t index = 0; index < vSubSum.size(); index++)
    {
        if(vSubSum[index] == k)
            iCount++;
        for(size_t i = 0; i < index; i++)
        {
            if(vSubSum[index] - vSubSum[i] == k)
                iCount++;
        }
    }
    return iCount;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    cout << subarraySum(vInt, 2) << endl;
    system("pause");
    return 0;
}