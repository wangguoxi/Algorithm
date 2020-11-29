/**
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char,int> hMap;
    vector<int> vLen(s.length(), 0);
    int iMaxLen = 0;
    for(size_t index = 0; index < s.length(); index++)
    {
        if(hMap.find(s[index]) != hMap.end())
        {
            vLen[index] = index  -1  - vLen[index - 1] + 1 > hMap[s[index]] ? vLen[index -1 ] + 1 : index - hMap[s[index]]; 
        }
        else
        {
            if(index == 0)
            {
                vLen[index] = 1;
            }
            else
            {
                vLen[index] = vLen[index-1] + 1;
            }
            
        }
         hMap[s[index]] = index;
         cout << index << "," << vLen[index] << endl;
        iMaxLen  = iMaxLen > vLen[index] ? iMaxLen : vLen[index];
    }
    return iMaxLen;
}

int main()
{
    string s("abba");
    cout << lengthOfLongestSubstring(s) << endl;
    system("pause");
    return 0;
}