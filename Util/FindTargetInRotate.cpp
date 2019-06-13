#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 搜索旋转排序数组,没有重复元素,如果有重复元素,一步一步移动
 * 时间复杂度使用log(n)
 * 1 2 3 4 6 6 6 6 9 10 15
 * 6 9 10 15 1 2 3 4 6 6 6
 */

int FindInRoate(const vector<int>& vInt,int key)
{
    int iBegin = 0;
    int iEnd = vInt.size() - 1;
    int iIndex = -1;
    while(iBegin <= iEnd)
    {
        int iMid = iBegin + (iEnd - iBegin)/2;
        if(vInt[iMid] == key)
        {
            iIndex = iMid;
            break;
        }
        else if(key > vInt[iMid])
        {
            if(vInt[iBegin] < vInt[iMid]) // 单调递增序列
            {
                iBegin = iMid + 1 ;
            }
            else if(vInt[iBegin] > vInt[iMid])  // 非单调序列 , 先增后降
            {
                key > vInt[iBegin] ? iEnd = iMid -1 : iBegin = iMid + 1;
            }
            else
            {
                iBegin++;
            }
            
        }
        else // key < vInt[iMid]
        {
            if(vInt[iBegin] < vInt[iMid]) // 单调递增
            {
                key > vInt[iBegin] ? iEnd = iMid - 1 : iBegin = iMid + 1; 
            }
            else  if(vInt[iBegin] > vInt[iMid])// 先增后降
            {
                iBegin = iMid + 1;
            }
            else
            {
                iBegin++;
            }    
        } 
    }
    return iIndex;
}

int main() 
{
    //  6 9 10 15 1 2 3 4 6 6 6
    vector<int> vInt;
    vInt.push_back(6);
    vInt.push_back(9);
    vInt.push_back(10);
    vInt.push_back(15);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(6);
    vInt.push_back(6);
    cout << FindInRoate(vInt, 6) << endl;

    system("pause");
    return 0;
}