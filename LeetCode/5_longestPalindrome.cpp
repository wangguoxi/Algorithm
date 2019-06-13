/*
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-palindromic-substring
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
    int iMaxLen = 0;
    int iMaxIndex = 0;
    vector<int> vFlag(s.length(), 0);
    for (size_t index = 0; index < s.length(); index++)
    {
        vFlag[index] = 1;
        if (index > 0)
        {
            if (s[index] == s[index - vFlag[index - 1]])
                vFlag[index] = vFlag[index -1] == 1 ? vFlag[index - 1] + 1 : vFlag[index -1] + 2;
        }
        if (vFlag[index] > iMaxLen)
        {
            iMaxLen = vFlag[index];
            iMaxIndex = index + 1 - vFlag[index];
        }
        cout << vFlag[index] << "," << iMaxLen << "," << iMaxIndex << "," << index << endl;
    }
    return s.substr(iMaxIndex, iMaxLen);
}

int main()
{
    string s("babad");

    cout << longestPalindrome(s) << endl;
    system("pause");
    return 0;
}