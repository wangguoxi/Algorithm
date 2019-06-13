#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 连续递增序列的长度
 */
int LongIncr(vector<int>& vInt)
{
    int iPreMaxLen = 0;  // 前面节点最长序列
    int iMaxLenIndex = -1; //单调递增序列的最后节点索引 
    int iMaxLen = 0; // 单调递增最大长度

    for(size_t index = 0 ; index < vInt.size() ; index++)
    {
        // 第一个节点
        if(index == 0)
        {
            iMaxLenIndex = 0;
            iPreMaxLen = 1;
            iMaxLen = 1;
        }
        else
        {
            if(vInt[index] >= vInt[index-1])
            {
                if(iPreMaxLen + 1 > iMaxLen)
                {
                    iMaxLen = iPreMaxLen + 1;
                    iMaxLenIndex = index;
                } 
                iPreMaxLen++;
            }
            else
            {
                iPreMaxLen = 1;   
            }
        }
    }
    
    return iMaxLen;
}

int main() 
{
    vector<int> vInt;
    vInt.push_back(6);
    vInt.push_back(7);
    vInt.push_back(4);
    vInt.push_back(5);
    vInt.push_back(3);
    vInt.push_back(8);
    vInt.push_back(30);
    vInt.push_back(1);
    vInt.push_back(0);
    
    cout << LongIncr(vInt) << endl;
    system("pause");
    return 0;
}