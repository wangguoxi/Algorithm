// https://leetcode-cn.com/problems/validate-stack-sequences/
/**
 给出一个单词列表，其中每个单词都由小写英文字母组成。

如果我们可以在 word1 的任何地方添加一个字母使其变成 word2，那么我们认为 word1 是 word2 的前身。例如，"abc" 是 "abac" 的前身。

词链是单词 [word_1, word_2, ..., word_k] 组成的序列，k >= 1，其中 word_1 是 word_2 的前身，word_2 是 word_3 的前身，依此类推。

从给定单词列表 words 中选择单词组成词链，返回词链的最长可能长度。
 
示例：

输入：["a","b","ba","bca","bda","bdca"]
输出：4
解释：最长单词链之一为 "a","ba","bda","bdca"。
 

提示：

1 <= words.length <= 1000
1 <= words[i].length <= 16
words[i] 仅由小写英文字母组成。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 校验序列是否为合法的入栈序列
bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    int iPushIndex = 0;
    int iPopIndex = 0;
    stack<int> st;
    if(pushed.size() != popped.size())
        return false;
    if(pushed.size() == 0)
        return true;
    for(; iPushIndex < pushed.size();)
    {
        if(pushed[iPushIndex] == popped[iPopIndex])
        {
            iPushIndex++;
            iPopIndex++;
        }
        else
        {
            // 在插入栈的过程中有可能需要出栈
            while (!st.empty() && iPopIndex < popped.size() && st.top() == popped[iPopIndex])
            {
                st.pop();
                iPopIndex++;
            }
            st.push(pushed[iPushIndex]);
            iPushIndex++;
        }
    }
    while(!st.empty() && iPopIndex < popped.size() && st.top() == popped[iPopIndex])
    {
        st.pop();
        iPopIndex++;
    }
    return st.empty();
}

int main()
{
    vector<int> pushed;
    vector<int> popped;
    pushed.push_back(1);
    pushed.push_back(2);
    pushed.push_back(3);
    pushed.push_back(4);
    pushed.push_back(5);
    
    popped.push_back(4);
    popped.push_back(3);
    popped.push_back(5);
    popped.push_back(1);
    popped.push_back(2);
    cout << validateStackSequences(pushed, popped) << endl;
    system("pause");
    return 0;
}