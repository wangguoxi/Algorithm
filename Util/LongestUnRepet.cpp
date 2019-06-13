#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 无重复字符的最长子串
 * 记录字符最后一个位置
 */

int LengthOfUnRepet(const string& sTr)
{
    unordered_map<char,int> hMap;
    int iMaxLength = sTr.length() > 0 ? 1 : 0;
    int iPreMaxLen = sTr.length() > 0 ? 1 : 0;
    for(int index = 0 ; index < sTr.length() ; index++)
    {
        if(hMap.find(sTr[index]) == hMap.end())
        {
            if(index != 0)
                iPreMaxLen++;
            
        }
        else
        {
            iPreMaxLen = min(index - hMap[sTr[index]],iPreMaxLen +1 );
        }
        hMap[sTr[index]] = index;
        iMaxLength = max(iMaxLength,iPreMaxLen);
        //cout << "char:" << sTr[index] << ",premaxlen:" << iPreMaxLen << ",maxlen:" << iMaxLength << endl;
    }
    return iMaxLength;
}


int main() 
{
    string str = "adfadfegdfajkg";
    cout <<  LengthOfUnRepet(str) << endl;
    system("pause");
    return 0;
}