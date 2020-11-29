// https://leetcode-cn.com/problems/shortest-distance-to-a-character/
/*
给定一个字符串 S 和一个字符 C。返回一个代表字符串 S 中每个字符到字符串 S 中的字符 C 的最短距离的数组。

示例 1:

输入: S = "loveleetcode", C = 'e'
输出: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
说明:

字符串 S 的长度范围为 [1, 10000]。
C 是一个单字符，且保证是字符串 S 里的字符。
S 和 C 中的所有字母均为小写字母。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> shortestToChar(string s, char c)
{
    vector<int> vPos;
    vector<int> vResult;
    for (size_t index = 0; index < s.length(); index++)
    {
        if (s[index] == c)
        {
            vPos.push_back(index);
        }
    }
    for (size_t index = 0; vPos.size() > 0 && index < s.length(); index++)
    {
        size_t begin = 0;
        size_t end = vPos.size();
        // 找到第一个
        while (begin < end)
        {
            int mid = begin + (end - begin) / 2;
            if (vPos[mid] >= index)
            {
                end = mid;
            }
            else // vInt[mid] < target
            {
                begin = mid + 1;
            }
        }
       // cout << "index:" << index << ",begin:" << begin << endl;
        if(begin == 0) //  if(index <= vPos[0])
        {
            vResult.push_back(vPos[0] - index);
        }
        else if(begin > vPos.size()) //  else if(index >= vPos[vPos.size() - 1])
        {
            vResult.push_back(index - vPos[vPos.size()-1]);
        }
        else // 中间数据
        {
            int iMin = vPos[begin] - index;
            if(begin >=1 && index < size_t(vPos[begin -1] + iMin))
                iMin =  index - vPos[begin -1];
            vResult.push_back(iMin);
        } 
    }
    return vResult;
}

int main()
{
    string s = "aaba";
    char c = 'b';
    vector<int> vInt = shortestToChar(s, c);
    for (size_t index = 0; index < vInt.size(); index++)
    {
        cout << vInt[index] << ",";
    }
    cout << endl;
    system("pause");
    return 0;
}