#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 排列 & 组合
 */

/**
 * 下一个排列组合,在一个字典序序列中，从尾往前找两个相邻的元素*i 和 *ii，
 * 其中第一个元素是*i ，第二个元素是*ii，保证这连个元素的关系是 *i < **ii
 * 然后从尾部开始再找一个元素 *j,使得 *j > *i, 置换 *i 和*j，
 * 然后再将ii后的所有元素都颠倒置换。
 */
bool NextPermutation(vector<int>& vInt)
{
    // 从后往前找一队元素
    int i = -1;
    int ii = -1;
    for(int index = vInt.size() -1 ; index >= 0 ; index--)
    {
        if(index - 1 >= 0 && vInt[index -1] < vInt[index])
        {
            i = index - 1;
            ii = index;
            break;
        }
    }
    if(i == -1 || ii == -1)
        return false;
        
    // 从尾部找到另一个元素j 使得 *j > *i
    int j = -1;
    for(int index = vInt.size() -1 ; index >= 0 ; index--)
    {   
        if(vInt[index] > vInt[i])
        {
            j = index;
            break;
        }
    }
    if(j == -1)
        return false;
        
    swap(vInt[i],vInt[j]);
    for(int begin = ii,end = vInt.size() -1 ; begin <= end ; begin++,end--)
        swap(vInt[begin],vInt[end]);
    for(int index = 0 ; index < vInt.size() ; index++)
        cout << vInt[index] << " ";
    cout << endl;
    return true;
}

/**
 * 上一个排列组合，在一个字典序序列中，从尾部往前找两个相邻的元素 *i 和 *ii,
 * 其中第一个元素是 *i，第二个元素是 *ii，使得这两个元素的关系是 *i > *ii,
 * 然后从尾部开始找一个元素 *j, 使得 *j < *i ,置换 *i 和 *j,
 * 然后再将 **后的所有元素都颠倒置换。
 */
bool PrePremutataion(vector<int>& vInt)
{
     // 从后往前找一队元素
    int i = -1;
    int ii = -1;
    for(int index = vInt.size() -1 ; index >= 0 ; index--)
    {
        if(index - 1 >= 0 && vInt[index -1] > vInt[index])
        {
            i = index - 1;
            ii = index;
            break;
        }
    }
    if(i == -1 || ii == -1)
         return false;
        
    // 从尾部找到另一个元素j 使得 *j > *i
    int j = -1;
    for(int index = vInt.size() -1 ; index >= 0 ; index--)
    {   
        if(vInt[index] < vInt[i])
        {
            j = index;
            break;
        }   
    }
    if(j == -1)
        return false;
        
    swap(vInt[i],vInt[j]);
    for(int begin = ii,end = vInt.size() -1 ; begin <= end ; begin++,end--)
        swap(vInt[begin],vInt[end]);
    for(int index = 0 ; index < vInt.size() ; index++)
        cout << vInt[index] << " ";
    cout << endl;
    return true;
}

bool IsSwap(vector<int>& vInt, int begin, int end)
{
    for(int index = begin; index < end; index++)
    {
        if(vInt[index] == vInt[end])
            return false;
    }
    return true;
}
// 使用递归查找对应的排列组合
void Premutataion(vector<int>& vInt,int begin,int end)
{
    if(begin >= end)
    {
        for(int index = 0 ; index < vInt.size() ; index++)
            cout << vInt[index] << " ";
        cout << endl;
        return ;
    }
    // 总是固定一个元素,计算剩下序列的排列组合
    for(int index = begin; index <= end; index++)
    {
        // 找到不相同的元素
       // if(index == begin || vInt[index] != vInt[index-1])
        if(IsSwap(vInt,begin,index))
        {
            swap(vInt[index],vInt[begin]);
            Premutataion(vInt,begin+1,end);
            swap(vInt[index],vInt[begin]);
        }    
    }
}

void Premutataion(vector<int>& vInt)
{
    sort(vInt.begin(),vInt.end());
    Premutataion(vInt,0,vInt.size()-1);
}

int main() 
{
    vector<int> vInt;
    vInt.push_back(6);
    vInt.push_back(6);
    vInt.push_back(7);
    
    Premutataion(vInt);
    system("pause");
    return 0;
}