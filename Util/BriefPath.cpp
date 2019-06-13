#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 简化linux路径，原地计算
 */
string BriefPath(const string& sSr)
{
    string sPath = sSr;
    int iBaseIndex = 0;
    if(sPath.length() <= 0 || sPath[0] != '/')
        return "";
    for(int index = 1; index < sPath.length() ; index++)
    {
        if(sPath[index] == '/') // 需要回退
        {
            if(sPath[iBaseIndex] == '.')
            {
                if(sPath[iBaseIndex-1] == '.')
                {
                    // 往前走
                    iBaseIndex = iBaseIndex - 3;
                    for(; iBaseIndex >= 0;iBaseIndex--)
                    {
                        if(sPath[iBaseIndex] == '/')
                        {
                            break;
                        }
                    }
                    continue;
                }
                else if(iBaseIndex -1 >= 0 && sPath[iBaseIndex - 1] == '/')
                {
                    iBaseIndex--;
                    continue;
                }    
            }
            else if (sPath[iBaseIndex] == '/')
            {   
                continue;  // 不是第一个重复的根路径
            }
        }
        iBaseIndex++;
        sPath[iBaseIndex] = sPath[index];     
    }
    return sPath.substr(0,iBaseIndex + 1);
}

int main() 
{
    string path = "/wang/./../";
    cout <<  BriefPath(path) << endl;
    system("pause");
    return 0;
}