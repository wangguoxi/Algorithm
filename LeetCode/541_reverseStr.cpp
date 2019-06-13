// https://leetcode-cn.com/problems/reverse-string-ii/
/**
 给定一个字符串和一个整数 k，你需要对从字符串开头算起的每个 2k 个字符的前k个字符进行反转。如果剩余少于 k 个字符，则将剩余的所有全部反转。如果有小于 2k 但大于或等于 k 个字符，则反转前 k 个字符，并将剩余的字符保持原样。

示例:

输入: s = "abcdefg", k = 2
输出: "bacdfeg"
要求:

该字符串只包含小写的英文字母。
给定字符串的长度和 k 在[1, 10000]范围内。
*/

#include <iostream>
#include <vector>
using namespace std;

string reverseStr(string s, int k)
{
    int sLen = s.length();
    int iSlot = 1;
    for(int i = 0; i < sLen; i+= k)
    {
        // 反转前K个
        int begin = i;
        int end = i + k - 1 < sLen ? i+k-1 : sLen - 1;
        while(iSlot % 2 == 1 && begin < end)
        {
            swap(s[begin++], s[end--]);
        }
        iSlot++;
    }
    return s;
}

int main()
{
    string s= "abcdefg";
    cout << reverseStr(s, 2) << endl;
    system("pause");
    return 0;
}