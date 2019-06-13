/**
 给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:

输入: nums = [1], k = 1
输出: [1]
说明：

你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。

链接：https://leetcode-cn.com/problems/top-k-frequent-elements
*/

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int,int> hMap;
    for(int index = 0; index < nums.size(); index++)
    {
        hMap[nums[index]]++;
    }
    map<int,vector<int> > mMap;
    vector<int> vInt,vResult;
    for(auto mItr = hMap.begin(); mItr != hMap.end(); mItr++)
    {
        mMap[mItr->second].push_back(mItr->first);
    }

    for(auto rit=mMap.rbegin();rit!=mMap.rend();rit++)
    {
        for(int index = 0; index < rit->second.size(); index++)
        {
            vResult.push_back(rit->second[index]);
            if(vResult.size() >= k)
                return vResult;
        }
    }
    return vResult;
}

int main()
{
    vector<int> vInt,vResult;
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(2);
    //1,1,1,2,2,3
    vResult = topKFrequent(vInt, 2);
    for(int index = 0; index < vResult.size(); index++)
    {
        cout << vResult[index] << ",";
    }
    cout << endl;
    system("pause");
    return 0;
}