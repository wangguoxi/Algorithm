#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// 判断某一个字符串是否为一个字符数组中单词的组合
/**
 * 给定一个字符串和一个字符串数组，判断该字符串是否可以由字符串数组中的单词组成。 
 * 思路:
 * 是有分治递归的思想，将入该字符串前半部分达到目标，后半部分也可以达到目标，最终就符合要求。
 */
bool Helper(const unordered_map<string,int>& mMap, const string& sTar,int begin,int end)
{
    if(begin > end)
        return true;
    for(int index = begin; index <= end; index++)
    {
        string sTmp = sTar.substr(begin, index - begin + 1);
        // 当前可以找到
        if(mMap.find(sTmp) != mMap.end() && Helper(mMap,sTar,index+1,end))
        {
            return true;
        } 
    }
    return false;
}

bool FindTarget(const vector<string>& vStr, const string& sTar)
{
    unordered_map<string,int> mMap;
    for(int index = 0 ; index < vStr.size() ; index++)
    {
        mMap[vStr[index]]  = index;
    }   
    return  Helper(mMap,sTar, 0,sTar.length()-1);
} 

int main()
{
    vector<string> vStr;
    vStr.push_back("I");
    vStr.push_back("love");
    vStr.push_back("byte");
    vStr.push_back("bytedance");
        
    string sTar("Ilove bytedance");
    cout << FindTarget( vStr,sTar) << endl;
    system("pause");
    return 0;
}