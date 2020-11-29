#include <iostream>
#include <vector>

using namespace std;

// 数组奇偶排序

void ResetOrder(vector<int>& vInt)
{
    int iLastIndex = -1;
    for(int index = 0; index < vInt.size(); index++)
    {
        if(vInt[index] % 2)
        {
            swap(vInt[++iLastIndex],vInt[index]);
        }
    }
}

void InvertOrder(vector<int>& vInt, int begin, int end)
{
    while(begin < end)
    {
        swap(vInt[begin++],vInt[end--]);
    }
}

void ResetOrderRelative(vector<int>& vInt)
{
    int iLastIndex = -1;
    for(int index = 0; index < vInt.size(); index++)
    {
        if(vInt[index] % 2)
        {
            iLastIndex++;
            InvertOrder(vInt, iLastIndex, index);
            InvertOrder(vInt,iLastIndex+1,index);
        }
    }
}

int main()
{
    vector<int> vInt;
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(4);
    vInt.push_back(5);
    vInt.push_back(6);
    //ResetOrder(vInt);
    ResetOrderRelative(vInt);
    for(int index = 0; index < vInt.size(); index++)
    {
        cout << vInt[index] << endl;
    }
    system("pause");
    return 0;
}

