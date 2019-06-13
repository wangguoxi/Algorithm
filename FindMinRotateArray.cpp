#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
/**
 * 在旋转数组中找到最小值 
 * 1 2 3 4 6 9 10 15
 * 6 9 10 15 1 2 3 4
 */
int MinNumberInRotateArray(vector<int> &rotateArray)
{
    int iMin = 0;
    int begin = 0;
    int end = rotateArray.size();
    while(begin < end)
    {
        int iMid = begin + (end - begin) / 2;
        if (rotateArray[begin] >= rotateArray[iMid])
        {
            begin = iMid;
        }
        else
        {
            end = iMid -   1;
        }
    }
    return rotateArray[begin];
}

int main()
{
    vector<int> vInt;
    vInt.push_back(6);
    vInt.push_back(9);
    vInt.push_back(10);
    vInt.push_back(15);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(3);
    vInt.push_back(4);
    cout << MinNumberInRotateArray(vInt) << endl;
    system("pause");
    return 0;
}