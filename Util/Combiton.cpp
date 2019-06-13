#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

// 组合
void combation(const vector<int>& vInt,int begin,int end,int size,vector<int>& vRes)
{
    if(begin >= end)
        return ;
    if(size == 0)
    {
        for(int index = 0 ; index < vRes.size(); index++)
            cout << vRes[index] << " ";
        cout << endl;
        return ;
    }
    vRes.push_back(vInt[begin]);
    combation(vInt,begin+1,end,size - 1,vRes);
    vRes.pop_back();
    combation(vInt,begin+1,end,size,vRes);
}

void combation(const vector<int>& vInt)
{
    for(int index = 1 ; index <= vInt.size(); index++)
    {
        vector<int> vRes;
        combation(vInt,0,vInt.size() - 1,index,vRes);
    }
}

/**
 * 数组的所有子,基本的思想可以想象成是一个二叉树，下一层的的结果是上一层结果尾部添加当前元素
 * 1、首先要排序
 * 2、当前元素如果和前面相当，那么直需要把上一轮添加进去的结果取出来，然后在尾部
 * 添加该元素即可。
 */
void combation(const vector<int>& vInt,vector<vector<int>>& vRes)
{
    vector<int> vTmp;
    vRes.push_back(vTmp); // 空子集

    // 对于每一个元素都是把之前的结果集添加该元素之后 再添加到结果中
    int iPreSize = 0;
    int iStart = 0;
    int iEnd = 1;
    for(int index = 0 ; index < vInt.size() ; index++)
    {
        // 根据当前元素和之前的元素是否相等来判断从上一轮的哪个位置元素
        iStart = index != 0 && vInt[index] == vInt[index-1] ? iPreSize : 0;
        iPreSize = vRes.size(); // 记录上一轮字节结果大小
        for(; iStart < iEnd ; iStart++)
        {
            vector<int> vTmp = vRes[iStart];
            vTmp.push_back(vInt[index]);
            vRes.push_back(vTmp);
        }
        iEnd = vRes.size();
    }
}

int main() 
{

    
    system("pause");
    return 0;
}