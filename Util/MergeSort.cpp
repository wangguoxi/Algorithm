#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/**
 *  归并排序 
 */
// 使用临时数组归并
void Merge(int *array, int begin, int iMid, int end)
{
    vector<int> vTmp;
    int iFirst = begin;
    int iSecond = iMid + 1;
    for (; iFirst <= iMid && iSecond <= end;)
    {
        if (array[iFirst] < array[iSecond])
        {
            vTmp.push_back(array[iFirst]);
            iFirst++;
        }
        else
        {
            vTmp.push_back(array[iSecond]);
            iSecond++;
        }
    }
    while (iFirst <= iMid)
    {
        vTmp.push_back(array[iFirst]);
        iFirst++;
    }
    while (iSecond <= end)
    {
        vTmp.push_back(array[iSecond]);
        iSecond++;
    }
    for (int index = 0; index < vTmp.size(); index++)
    {
        array[begin] = vTmp[index];
        begin++;
    }
}

void reverse(int *data, int left, int right)
{
    int *p1 = &data[left];
    int *p2 = &data[right];
    while (p1 < p2)
    {
        int t = *p1;
        *p1 = *p2;
        *p2 = t;
        p1++;
        p2--;
    }
}

void tripletwo(int *data, int left, int mid, int right)
{
    reverse(data, left, mid);
    reverse(data, mid + 1, right);
    reverse(data, left, right);
}

void tripleone(int *data, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int index = j;
    while (j <= right && i < j)
    {
        while (data[i] <= data[j] && i < j) //注意这里，如果是 <= 那么优化后的归并排序是稳定的，否则就是不稳定的
        {
            i++;
        }
        if (i == j)
            break;
        index = j;
        while (data[j] < data[i] && j <= right)
            j++; //这里没有上面的影响，仔细想一下就会明白
        tripletwo(data, i, index - 1, j - 1);
        i += j - index; //j-1-index+1=j-index(后一段的长度)，记住小心这里j是比data[i]大的，data[j-1]才是要移动的字段的后端
    }
}

// 原地反转
void reverse(int *array, int iFirst, int index, int second)
{
    int begin = iFirst;
    int end = index - 1;
    while (begin < end)
    {
        swap(array[begin], array[end]);
        begin++;
        end--;
    }
    begin = index;
    end = second;
    while (begin < end)
    {
        swap(array[begin], array[end]);
        begin++;
        end--;
    }

    begin = iFirst;
    end = second;
    while (begin < end)
    {
        swap(array[begin], array[end]);
        begin++;
        end--;
    }
}

void MergeV2(int *array, int begin, int iMid, int end)
{
    // [begin,iMid] [iMid+1,end] 原地归并
    int iSecond = iMid + 1;
    int iFirst = begin;
    int index = iSecond;
    for (; iSecond <= end && iFirst < iSecond;)
    {
        while (iFirst < iSecond && array[iFirst] <= array[iSecond])
            iFirst++;
        if (iFirst == iSecond)
            break;
        index = iSecond;
        while (iSecond <= end && array[iSecond] < array[iFirst])
            iSecond++;
        // [iFirst,index-1]
        // cout << iFirst << " " << index << " " << iSecond - 1 << endl;
        reverse(array, iFirst, index, iSecond - 1);
        // tripletwo(array,iFirst,index-1,iSecond-1);
        iFirst += iSecond - index;
    }
}

// 归并排序 [begin, end]
void MergeSort(int *array, int begin, int end)
{
    if (begin < end)
    {
        int iMid = begin + (end - begin) / 2;
        MergeSort(array, begin, iMid);
        MergeSort(array, iMid + 1, end);
        // tripleone(array, begin, iMid, end);
        MergeV2(array, begin, iMid, end);
    }
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
    MergeSort(&vInt[0], 0, vInt.size()-1);
    for(int index = 0; index < vInt.size(); index++)
        cout << vInt[index] << endl;
    system("pause");
    return 0;
}