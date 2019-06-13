#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/**
 * 查找TopK元素,借助最大堆来实现 
 */
// 堆排序
// 下沉操作
void DownStream(int *array, int pos, int size)
{
    // 调整pos位置的节点信息
    int iLeft = pos * 2 + 1;
    int iRight = pos * 2 + 2;
    while (1)
    {
        int iMaxPos = pos;
        if (iLeft < size && array[iLeft] < array[iMaxPos])
            iMaxPos = iLeft;
        if (iRight < size && array[iRight] < array[iMaxPos])
            iMaxPos = iRight;
        if (iMaxPos == pos)
            break;
        swap(array[pos], array[iMaxPos]);
        pos = iMaxPos;
        iLeft = pos * 2 + 1;
        iRight = pos * 2 + 2;
    }
}

// 上浮操作
void UpStream(int *array, int size)
{
    int index = size - 1;
    int iParent = (index - 1) / 2;
    while (index != 0 && iParent >= 0)
    {
        if (array[iParent] < array[index])
            break;
        swap(array[iParent], array[index]);
        index = iParent;
        iParent = (index - 1) / 2;
    }
}

void MakeHeap(int *array, int size)
{
    for (int index = size / 2 - 1; index >= 0; index--)
    {
        DownStream(array, index, size);
    }
}

void HeapSort(int *array, int size)
{
    MakeHeap(array, size);
    for (int index = size - 1; index >= 0; index--)
    {
        swap(array[0], array[index]);
        DownStream(array, 0, index);
    }
}

// 找最大的第K数

int FindKTh(int *array, int k, int size)
{
    vector<int> vTmp;
    for (int index = 0; index < size; index++)
    {
        if (index < k)
            vTmp.push_back(array[index]);
        else
        {
            if (index == k)
            {
                MakeHeap(&vTmp[0], k);
            }
            if (array[index] > vTmp[0])
            {
                vTmp[0] = array[index];
                DownStream(&vTmp[0], 0, k);
            }
        }
    }
    return vTmp[0];
}

int main()
{

    vector<int> vInt;
    vInt.push_back(-1);
    vInt.push_back(0);
    vInt.push_back(3);
    vInt.push_back(5);
    vInt.push_back(9);
    vInt.push_back(12);
    cout << FindKTh(&vInt[0], 3, 6);
    system("pause");
    return 0;
}