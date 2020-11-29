#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/**
 * 快速排序
 */
// 查找对应的分割位置
int GetPosition(int *array, int begin, int end)
{
    // 第一个作为基准
    /*
     最后的分割点iPreIndex是最后一个比基准点小的元素，
     iPreIndex之后的元素都不小于基准值。但是分割点并不一定是以基准点为标准
     */
    int iTarget = array[begin];
    int iPreIndex = begin - 1;
    for (int index = begin; index <= end; index++)
    {
        if (array[index] < iTarget)
        {
            iPreIndex++;
            swap(array[iPreIndex], array[index]);
        }
    }
    return iPreIndex; // 最后一个比目标元素小的位置
}

// [begin, end]
void QuickSort(int *array, int begin, int end)
{
    if (begin < end)
    {
        int iPos = GetPosition(array, begin, end);
        QuickSort(array, begin, iPos);
        if (begin > iPos)
        {
            QuickSort(array, iPos + 2, end);
        }
        else
        {
            QuickSort(array, iPos + 1, end);
        }
    }
    return;
}

// [begin, end]
int GetPositionV2(int *array, int begin, int end)
{
    int iTarget = array[begin]; // 第一个元素作为基准值
    int left = begin;
    int right = end;
    while (begin < end)
    {
        // 从左到右找到第一个比基准值大的元素
        while (begin <= right && array[begin] <= iTarget)
            begin++;
        // 从右到左找到第一个不比基准值大的元素
        while (end >= left && array[end] > iTarget)
            end--;
        if (begin < end)
            swap(array[begin], array[end]);
    }
    swap(array[end], array[left]);
    return end;
}

// [begin, end] 升序
int GetPositionV3(int *array, int begin, int end)
{
    int iTarget = array[begin]; // 第一个元素作为基准值
    int left = begin;
    while (begin != end)
    {    
        // 从右到左找到第一个比基准值小的元素
        while (end > left && array[end] >= iTarget)
            end--;
        // 从左到右找到第一个比基准值大的元素
        while (begin < end && array[begin] <= iTarget)
            begin++;
        if (begin < end)
            swap(array[begin], array[end]);
    }
    swap(array[end], array[left]);
    return end;
}

// [begin, end] 降序
int GetPositionV4(int *array, int begin, int end)
{
    int iTarget = array[begin]; // 第一个元素作为基准值
    int left = begin;
    while (begin != end)
    {    
        // 从右到左找到第一个比基准值小的元素
        while (end > left && array[end] <= iTarget)
            end--;
        // 从左到右找到第一个比基准值大的元素
        while (begin < end && array[begin] >= iTarget)
            begin++;
        if (begin < end)
            swap(array[begin], array[end]);
    }
    swap(array[end], array[left]);
    return end;
}

void QuickSortV2(int *array, int begin, int end)
{
    if (begin < end)
    {
        int iPos = GetPositionV3(array, begin, end);
        QuickSortV2(array, begin, iPos-1);
        QuickSortV2(array, iPos + 1, end);
    }
}

int main()
{
    vector<int> vInt;

    vInt.push_back(-1);
    vInt.push_back(0);
    vInt.push_back(5);
    vInt.push_back(9);
    vInt.push_back(12);
    vInt.push_back(3);
   
    /*
    vInt.push_back(5);
    vInt.push_back(7);
    vInt.push_back(3);
    vInt.push_back(2);
    vInt.push_back(9);
    vInt.push_back(1);
    vInt.push_back(10);
    vInt.push_back(8);
  */ 
    QuickSortV2(&vInt[0], 0, vInt.size() - 1);
    for (int index = 0; index < vInt.size(); index++)
        cout << vInt[index] << endl;
    system("pause");
    return 0;
}