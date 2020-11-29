
/**
 * 给你一个长度为 n 的数组，其中只有一个数字出现了奇数次，
 * 其他均出现偶数次，问如何使用优秀的时空复杂度快速找到这个数字。
 * 1、两个相同的数，异或之后为0，所有的数进行异或，相当于那个出现次数为奇数的数
 * 然后在分析最后的结果。
 */
#include <iostream>
#include <vector>
using namespace std;

int FindTarget(const vector<int>& vInt)
{
    int result = 0;
    for(int index = 0; index < vInt.size(); index++)
    {
        result = (result ^ vInt[index]);
    }
    return result;
}
int main()
{
    vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(4);
    vInt.push_back(1);
    vInt.push_back(1);
    cout << FindTarget(vInt) << endl;
    system("pause");
    return 0;
}
