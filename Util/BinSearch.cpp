#include <iostream>
#include <vector>
using namespace std;
/**
 * 集中二分查找的方法
 */

// [being,end]
bool BinSearchV2(const vector<int>& vInt, int begin, int end, int target)
{
    while(begin <= end)
    {
        int mid = begin + (end - begin)/2;
        if(vInt[mid] == target)
        {
            return true;
        }
        else if(vInt[mid] > target)
        {
            end = mid -1;
        }
        else  // vInt[mid] < target
        {
            begin = mid + 1;
        }
    }
    return false;
}

// [begin,end)
bool BinSearch(const vector<int>& vInt, int begin, int end, int target)
{
    while(begin < end)
    {
        int mid = begin + (end - begin)/2;
        if(vInt[mid] == target)
        {
            return true;
        }
        else if(vInt[mid] > target)
        {
            end = mid;
        }
        else
        {
            begin = mid + 1;
        }
    }
    return false;
}

// [begin,end), 在有序数组中找到target最左边的插入位置，也就是找到第一个不小于该值的位置
int BinSearchLeft(const vector<int>& vInt, int begin, int end, int target)
{
    while(begin < end)
    {
        int mid = begin + (end - begin)/2;
        if(vInt[mid] >= target)
        {
            end = mid;
        }
        else // vInt[mid] < target
        {
            begin = mid + 1;
        }
    }
    return begin;
}

// [begin,end) 在有序数组中找到target最右边的插入位置，也就是找到第一个大于该值得位置
int BinSearchRight(const vector<int>& vInt, int begin, int end, int target)
{
    while(begin < end)
    {
        int mid = begin + (end - begin)/2;
        
        if(vInt[mid] <= target)
        {
            begin = mid + 1;
        }
        else // vInt[mid] > target
        {
            end = mid;
        }
    }
    return begin;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(1);   
    
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(1);
    vInt.push_back(2);
    vInt.push_back(2);
    vInt.push_back(5);
    vInt.push_back(7);
    vInt.push_back(8);
    vInt.push_back(9);
    vInt.push_back(100);
    

   // cout << BinSearchV2(vInt, 0, vInt.size() -1,8) << endl;
   // cout << BinSearch(vInt, 0, vInt.size(), 8) << endl;
    cout << BinSearchLeft(vInt,0,vInt.size(),3) << endl;
    cout << BinSearchRight(vInt, 0, vInt.size(), 1) << endl;
    system("pause");
    return 0;
}