#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

/**
 * KMP
 */
void GetNext(char *parten, vector<int> &next)
{
    int i = 0;
    int j = -1;
    next[0] = -1;
    for (i = 0; i < strlen(parten) - 1;)
    {
        if (j == -1 || parten[i] == parten[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    for(int index = 0; index < next.size(); index++)
    {
        cout << next[index] << ",";
    }
    cout << endl;
}

int KMP(char *src, char *parten)
{
    vector<int> next(strlen(parten));
    int k = 0;
    int i = 0;
    int srcLen = strlen(src);
    int parLen = strlen(parten);
    GetNext(parten, next);
    //for (i = 0; i < strlen(src) && k < strlen(parten);) // strlen是unsigned_int k有可能为-1
    for (i = 0; i < srcLen && k < parLen;)
    {
        if (k == -1 || src[i] == parten[k])
        {
            i++;
            k++;
            cout << "i:" << i << ",k:" << k << endl;
        }
        else
        {
            k = next[k];
            cout << "!=,k:" << k << endl;
        }
    }
    //cout << k << " " << i << endl; // -1 1
    if (k == strlen(parten))
        return i - k;
    return -1;
}

int main()
{
    char* src = "fadfdjgr";
    char* parten = "fdjg";
    cout << strlen(src) << "," << strlen(parten) << endl;
    cout << KMP(src, parten);
    system("pause");
    return 0;
}