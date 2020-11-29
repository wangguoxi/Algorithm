/**

 给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：

输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。

链接：https://leetcode-cn.com/problems/intersection-of-two-arrays-ii
 */

#include <unordered_map>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
{
    vector<int> vResult;
    unordered_map<int,int> hMap;
    map<int,int> mMap;
    for(size_t index = 0; index < nums1.size(); index++)
    {
        hMap[nums1[index]]++;
    }
    for(size_t index = 0; index < nums2.size(); index++)
    {
        mMap[nums2[index]]++;
    }
    for(auto mItr = mMap.begin(); mItr != mMap.end(); mItr++)
    {
        if(hMap.find(mItr->first) != hMap.end())
        {
            int iCount = mItr->second;
            iCount = iCount < hMap[mItr->first] ? iCount : hMap[mItr->first];
            for(int index = 0; index < iCount; index++)
                vResult.push_back(mItr->first);
        }
    }
    return vResult;
}
int main()
{
    vector<int> vResult,nums1, nums2;
    nums1.push_back(2);
    nums1.push_back(2);
    
    
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(1);
    
    vResult = intersect(nums1, nums2);
    for(size_t index = 0; index < vResult.size(); index++)
    {
        cout << vResult[index] << ",";
    }
    system("pause");
    return 0;
}