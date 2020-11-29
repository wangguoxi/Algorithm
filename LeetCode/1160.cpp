#include <iostream>
#include <vector>
using namespace std;

int Length(const vector<string>& vStr, const string& str)
{
    vector<char> vHash(26,0);
    for(int index = 0; index < str.length(); index++)
    {
        if(str[index] < 'a' || str[index] > 'z')
        {
            return 0;
        }
        vHash[str[index] - 'a']++;
    }
    int result = 0;
    for(int index = 0; index < vStr.size(); index++)
    {
        vector<char> vTmp = vHash;
        bool bFind = true;
        for(int i = 0; i< vStr[index].length(); i++)
        {
            vTmp[vStr[index][i] - 'a']--;
            if(vTmp[vStr[index][i] - 'a'] < 0)
            {
                bFind = false;
                break;
            }
        }
        if(bFind)
            result += vStr[index].length();
    }
    return result;
}

int main()
{
    vector<string> vStr;
    
    vStr.push_back("cat");
    vStr.push_back("hello");
    vStr.push_back("word");
    cout << Length(vStr,"helloword");
    system("pause");
    return 0;
}