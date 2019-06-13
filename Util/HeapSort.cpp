#include <iostream>
#include <vector>
using namespace std;

/*
    堆排序
*/
// 调整堆
void Adjust(vector<int>& vInt,int index,int size)
{  
    int iMinIndex = index;
    int iLeft = index * 2 + 1;
    int iRight = index * 2 + 2;    
    for(; ;)
    {   
        iMinIndex = index;
        if(iLeft < size && vInt[iLeft] < vInt[iMinIndex])
            iMinIndex = iLeft;
        if(iRight < size && vInt[iRight] < vInt[iMinIndex])
            iMinIndex = iRight;
        if(iMinIndex == index)
            break;
        swap(vInt[iMinIndex],vInt[index]);
        index = iMinIndex;
        iLeft = index * 2 + 1;
        iRight = index * 2 + 2;
    }
}

// 构造最小堆
void MakeMinHeap(vector<int>& vInt)
{
    for(int index = (vInt.size() + 1) /2; index >= 0 ; index--)
    {
        Adjust(vInt,index,vInt.size());
    }
}

// 堆排序
void HeapSort(vector<int>& vInt)
{
    MakeMinHeap(vInt);
    for(int index = vInt.size() -1 ; index > 0 ; index--)
    {
        swap(vInt[0],vInt[index]);
        Adjust(vInt,0,index);
    }
}

int main()
{
    vector<int> vInt;
    vInt.push_back(4);
    vInt.push_back(3);
    vInt.push_back(5);
    vInt.push_back(8);
    vInt.push_back(1);
    vInt.push_back(10);
    vInt.push_back(49);
    vInt.push_back(6);
    vInt.push_back(2);
    HeapSort(vInt);
    for(int index = 0 ; index < vInt.size(); index++)
        cout << vInt[index] << " ";
    cout << endl;
    system("pause");
    return 0;
}