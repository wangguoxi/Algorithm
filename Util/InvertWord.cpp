#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstring>
using namespace std;

/**
 * 反转字符串里的单词
 * 先反转整个句子,再反转内部的单词
 */
void Invert(char* sTr, int begin, int end)
{   
    while(begin <= end)
    {
        swap(sTr[begin],sTr[end]);
        begin++;
        end--;
    }
}

void Invert(char* sTr,int len)
{
    Invert(sTr,0,len);
    
    int begin = 0;
    int end = 0;
    for(end = begin;begin <= len, end <=len ; )
    {
        if(sTr[begin]  == ' ')
        {
            begin++;
            continue;
        }    
        end = begin;
        for(; end <= len; end++)
            if(sTr[end] == ' ')
                break;
        if(end <= len)
            Invert(sTr,begin,end-1);
        begin = end;
    }  
}

int main() 
{
    char str[] = "I am student!";
    Invert(str, 12); 
    cout << str << endl;
    system("pause");
    return 0;
}