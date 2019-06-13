#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 最长公共前缀
 * 查找字符串数组中的最长公共前缀
 * 不能提前退出
 */
string LongestCommPre(const vector<string>& vStr)
{
    // 找到最短的一个字符串 然其他字符串和该字符串比较
    int iMinLenIndex = 0;
    int iMinLen = vStr.size() > 0 ? int(vStr[0].length()) : numeric_limits<int>::max();
    string sRes("");
    for(int index = 1; index < vStr.size() ; index++)
    {
        if(vStr[index].length() < iMinLen)
        {
            iMinLen = vStr[index].length();
            iMinLenIndex = index;
        }
    }
    if(iMinLen != numeric_limits<int>::max())
    {
        sRes = vStr[iMinLenIndex];
        // process
        int index = 0;
        for( ; index < sRes.length() ; index++)
        {
            for(int iComPreLen = 0 ; iComPreLen < vStr.size(); iComPreLen++)
            {
                if(vStr[iComPreLen][index] != sRes[index])
                {
                    
                    sRes = sRes.substr(0,index);
                }
                
            }   
        }
    }
   
    return sRes;
}

int main() 
{
    vector<string> vStr;
    vStr.push_back("adcdffdaf");
    vStr.push_back("adfdffdaf");
    vStr.push_back("addffdaf");
    vStr.push_back("adcdffdaf");
    cout << LongestCommPre(vStr) << endl;
    system("pause");
    return 0;
}