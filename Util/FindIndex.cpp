/*
给定m个不重复的字符 [a, b, c, d]，以及一个长度为n的字符串tbcacbdata，
问能否在这个字符串中找到一个长度为m的连续子串，
使得这个子串刚好由上面m个字符组成，顺序无所谓，
返回任意满足条件的一个子串的起始位置，
未找到返回-1。比如上面这个例子，acbd，3。
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int FindTarget(const vector<char>& vChar, const string& sStr)
{
    if(sStr.length() < vChar.size())
    {
        return -1;
    }
    unordered_map<char,int> mMap;
    for(int index = 0; index < vChar.size() ; index++)
    {
        mMap[vChar[index]] = -1; // 记录的是处理当前元素在这个序列中第几个
    }
    // 查找
    int iSize = vChar.size();
    int index = 0;
    for(index = 0; index < sStr.length(); index++)
    {
        unordered_map<char,int> tmpMap = mMap;
        iSize = vChar.size();
        for(int i = index ; iSize > 0 && i < index + vChar.size(); i++)
        {
            if(tmpMap.find(sStr[i]) != tmpMap.end())
            {
                int iCount = tmpMap[sStr[i]];
                if(iCount > 0)  // 不是第一次出现
                {
                    break;
                }
                else
                {
                    iSize--;
                    tmpMap[sStr[i]] = vChar.size() - iSize; // 当前字符在内是连续处理的第几个字符
                }
            } 
            else
            {
                break;
            }     
        }
        if(iSize == 0)
            break;
    }
    if( iSize== 0) 
       return index;
    return -1;
}

int FindTargetV2(const vector<char>& vChar, const string& sStr)
{
    if(sStr.length() < vChar.size())
    {
        return -1;
    }
    unordered_map<char,int> mMap;
    for(int index = 0; index < vChar.size(); index++)
    {
        mMap[vChar[index]] = -1; // 记录的是处理当前元素在这个序列中第几个
    }
    int iSize = vChar.size(); // 还剩这么多字符没有找到
    int index = 0;
    // 开始查找 
    for(index = 0; index < sStr.length(); index++)
    {
       // cout << index << endl;
        if(mMap.find(sStr[index]) != mMap.end())
        {
            int iPos = mMap[sStr[index]];
            if(iPos >= 0)  // 不是第一次出现,之前处理过, 需要根据位置和当前剩余的字符个数总和判断
            {
                // 上一个相同的字符所在的位置在这次处理的数据的前面，当前字符在这一轮查找中算新的
                /**
                 *  t b c a b a c d
                 *  第二个c的时候,此时的查找是从前面的b开始的，上一个c已经是上一轮的事情了
                 */
                if(iPos < index - (vChar.size() - iSize)) // 上一个相同的字符所在
                {
                    mMap[sStr[index]] = index; 
                    iSize--;
                }
                else // 当前这一轮中有重复的，那么重复的字符后面都是下一轮已经查找到的
                {
                    mMap[sStr[index]] = index;
                    iSize = vChar.size() - (index - iPos);
                }
            }
            else
            {
                iSize--;
                mMap[sStr[index]] = index; // 记录在sStr和当前字符匹配的索引
            }
        }
        else
        {
            iSize = vChar.size(); // 从下一个继续找这么多个连续的字符
        }
        if(iSize == 0)
            break;
    }
     if( iSize== 0) 
       return index - vChar.size() + 1;
    return -1;
}

int main() {
    vector<char> vChar;
    string str("tbcatcbdata");
    vChar.push_back('a');
    vChar.push_back('b');
    vChar.push_back('c');
    vChar.push_back('d');
    cout << FindTarget(vChar,str) << endl;
    cout << FindTargetV2(vChar,str) << endl;
    system("pause");
    return 0;
}