#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 合并区间
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 1、首先按照集合的第一个进行排序，然后进行合并
 */
struct SetInfo {
    int iBegin;
    int iEnd;
};

int cmp(const SetInfo& first,const SetInfo& second)
{
    return first.iBegin < second.iBegin;
}

void MergeSet(vector<SetInfo>& vSet)
{
    sort(vSet.begin(),vSet.end(),cmp);
    
    int iPreIndex = 0;
    for(size_t index = 1 ; index < vSet.size() ; index++)
    {
        if(vSet[index].iBegin >= vSet[iPreIndex].iBegin && vSet[index].iBegin <= vSet[iPreIndex].iEnd)
        {
            if(vSet[index].iEnd > vSet[iPreIndex].iEnd)
                vSet[iPreIndex].iEnd = vSet[index].iEnd;
            
        }
        else
        {
            iPreIndex++;
            vSet[iPreIndex]  = vSet[index];
        }
    }
    vector<SetInfo> vTmp(vSet.begin(),vSet.begin() + iPreIndex + 1);
    vSet.swap(vTmp);
    return ;
}

int main() 
{
    int array[] = {6,7,4,5,3,8,3,1,0};
    
    system("pause");
    return 0;
}