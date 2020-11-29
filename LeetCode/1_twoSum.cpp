// https://leetcode-cn.com/problems/two-sum/
/**
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/
#include <iostream>
#include <vector>
//#include <unorder_map>
#include <map>
using namespace std;
/**
 * 在一个数组中找出两个数之和等于指定的数
 */

struct stPos
{
    int iFirst;
    int iSecond;
};

void TwoSum(int iTarget,vector<int>& vInt,vector<stPos>& vPos)
{
    map<int,int> mIndex;
    map<int,int>::iterator mItr;
    for(int index = 0 ; index < vInt.size() ; index++)
    {
        int iTmp = iTarget - vInt[index];
        mItr = mIndex.find(iTmp) ;
        if(mItr != mIndex.end())
        {
            stPos pos;
            pos.iFirst = mItr->second;
            pos.iSecond = index;
            vPos.push_back(pos);
        }
        mIndex[vInt[index]] = index;
    }
}

void print(vector<stPos>& vPos)
{
    for(int index = 0; index < vPos.size() ; index++)
    {
        cout << "first:" << vPos[index].iFirst << ",second:" << vPos[index].iSecond << endl;
    }
}

int main()
{
    vector<int> vInt;
    vector<stPos> vPos;
    vInt.push_back(5);
    vInt.push_back(8);
    vInt.push_back(7);
    vInt.push_back(9);
    vInt.push_back(2);
    vInt.push_back(4);
    vInt.push_back(3);
    vInt.push_back(10);
    vInt.push_back(12);
    vInt.push_back(21);
    TwoSum(15,vInt,vPos);
    print(vPos);
    system("pause");
    return 0;
}