#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 1、三数之和
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足
 */
// 三数之和为0,相当于两个数之和是另外一个数的相反数

void SumFan(const vector<int>& vInt,int iExp,vector<int>& vRes)
{
    int iTarget = vInt[iExp] * (-1);
    unordered_map<int,int> hMap;
    for(int index = 0 ; index < vInt.size() ; index++)
    {
        if(index == iExp)
            continue;
        int iTmp = iTarget - vInt[index];
        auto iTr = hMap.find(iTmp);
        if(iTr != hMap.end())
        {
            vRes.push_back(iExp);
            vRes.push_back(index);
            vRes.push_back(iTr->second);
        }
        else
        {
            hMap[vInt[index]] = index;
        } 
    }
}

void SumThree(const vector<int>& vInt)
{
    for(int index = 0 ; index < vInt.size() ; index++)
    {
        vector<int> vIndex;
        SumFan(vInt,index,vIndex);
        for(int i = 0 ; i < vIndex.size() ; i++)
            cout << vIndex[i] << " ";
        cout << endl;
    }
}


// 三数之和
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < nums.size(); ++k) {
            if (nums[k] > 0) break;
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            int target = 0 - nums[k];
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return res;
    }
};

int main() 
{
    system("pause");
    return 0;
}