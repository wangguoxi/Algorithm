/**
找到给定字符串（由小写字符组成）中的最长子串 T ， 要求 T 中的每一字符出现次数都不少于 k 。输出 T 的长度。
示例 1:
输入:
s = "aaabb", k = 3
输出:
3
最长子串为 "aaa" ，其中 'a' 重复了 3 次。
示例 2:
输入:
s = "ababbc", k = 2
输出:
5
最长子串为 "ababb" ，其中 'a' 重复了 2 次， 'b' 重复了 3 次。
链接：https://leetcode-cn.com/problems/longest-substring-with-at-least-k-repeating-characters
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

/*
int longestSubstring(string s, int k)
{
    // 1、从首位开始找K个字符，然后往后遍历
    int iMaxLen = 0;
    for(size_t index = 0; index < s.length() - k; index++)
    {
        unordered_map<char,int> hMap; // 每个元素的个数
        int iCount = 0;  // K个数字还有多少个数据需要处理
        for(size_t i = index; i < s.length(); i++)
        {
            hMap[s[i]]++;
            if(hMap[s[i]] == 1)
            {
                iCount++;
            }
            else if(hMap[s[i]] == k)
            {
                iCount--;
            }
            if(iCount == 0)
            {
                iMaxLen = iMaxLen > i - index + 1 ? iMaxLen : (i - index + 1);
            }
        }
    }
    return iMaxLen;
}*/

int longestSubstring(string s, int k)
{
    // 1、从首位开始找K个字符，然后往后遍历
    int iMaxLen = 0;
    int iCount = 0;
    int iBegin = 0;
    unordered_map<char, int> hMap; // 每个元素的个数
    unordered_map<char, int> hEnd; // 某个字符在当前字符串中最后的位置
    for (size_t index = 0; index < s.length() - 1; index++)
    {   
        hEnd[s[i]] = index;
        hMap[s[i]]++;
        if (hMap[s[i]] == 1)
        {
            iCount++;
        }
        else if (hMap[s[i]] == k)
        {
            iCount--;
        }
        // 什么时候删除前面的呢
        
        if (iCount == 0)
        {
            iMaxLen = iMaxLen > index - begin + 1 ? iMaxLen : (index - begin + 1);
        }
    }
    return iMaxLen;
}

int main()
{
    string s("aaabb");
    cout << longestSubstring(s, 3) << endl;
    system("pause");
    return 0;
}