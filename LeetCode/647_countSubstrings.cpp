// https://leetcode-cn.com/problems/palindromic-substrings/
/**
 给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被计为是不同的子串。

示例 1:

输入: "abc"
输出: 3
解释: 三个回文子串: "a", "b", "c".
示例 2:

输入: "aaa"
输出: 6
说明: 6个回文子串: "a", "a", "a", "aa", "aa", "aaa".
注意:

输入的字符串长度不会超过1000。
*/

#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s)
{
      int iCount = 0;
    size_t tmp = 0;
    for (size_t index = 0; index < s.length(); index++)
    {
        // 以 s[index] 为子串的回文串
        // 以 s[index] 为中心构成的回文串
        tmp = 0;
        while (index >= tmp && index + tmp < s.length())
        {
            if (s[index - tmp] == s[index + tmp])
            {
                iCount++;
                tmp++;
            }
            else
            {
                break;
            }
        }
        // 以 s[index] 和 s[index-1]为中心构成回文串
        tmp = 0;
        while (index >= tmp + 1 && index + tmp < s.length())
        {
            if (s[index - tmp - 1] == s[index + tmp])
            {
                iCount++;
            }
            else
            {
                break;
            }
            tmp++;
        }
    }
    return iCount;  
}

int main()
{
    string s = "itsbeenalongtime";
    cout << countSubstrings(s) << endl;
    system("pause");
    return 0;
}