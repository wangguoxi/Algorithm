// https://leetcode-cn.com/problems/sort-array-by-parity/
/*
给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。

你可以返回满足此条件的任何数组作为答案。

示例：

输入：[3,1,2,4]
输出：[2,4,3,1]
输出 [4,2,3,1]，[2,4,1,3] 和 [4,2,1,3] 也会被接受。
 

提示：

1 <= A.length <= 5000
0 <= A[i] <= 5000
*/
#include <iostream>
#include <vector>
using namespace std;
vector<int> sortArrayByParity(vector<int> &A)
{
    int iPre = -1;
    for(size_t index = 0; index < A.size(); index++)
    {
        if(A[index] % 2 == 0)
        {
            iPre++;
            swap(A[iPre], A[index]);
        }
    }
    return A;
}
int main()
{
    vector<int> vInt;
    // 3,1,2,4
    vInt.push_back(3);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(4);
    vInt = sortArrayByParity(vInt);
    for(size_t index = 0; index < vInt.size(); index++)
        cout << vInt[index] << ",";
    system("pause");
    return 0;
}