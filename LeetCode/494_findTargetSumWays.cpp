/*
给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选择一个符号添加在前面。

返回可以使最终数组和为目标数 S 的所有添加符号的方法数。

示例 1:

输入: nums: [1, 1, 1, 1, 1], S: 3
输出: 5
解释: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

一共有5种方法让最终目标和为3。
注意:

数组非空，且长度不会超过20。
初始的数组的和不会超过1000。
保证返回的最终结果能被32位整数存下。
链接：https://leetcode-cn.com/problems/target-sum
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findTargetSumWays(vector<int> &nums, int S)
{
    if (S < 0)
        return 0;
    int iCount = 0;
    int iLoop = 1 << nums.size();
    cout << iLoop << endl;
    for (int index = 0; index <= iLoop - 1; index++)
    {
        int iSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            iSum += ((index >> i) & 1 == 1) ? nums[i] : (nums[i] * (-1));
        }
        if (iSum == S)
            iCount++;
    }
    return iCount;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    cout << findTargetSumWays(vInt, 3) << endl;
    system("pause");
    return 0;
}