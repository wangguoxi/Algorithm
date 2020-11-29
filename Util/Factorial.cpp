#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/**
 * 大数阶乘
 */
string Mulpti(const string& sFirst, const string&  sSecond)
{
    string sResult(sFirst.length() + sSecond.length(), '0');
    int iAdd = 0;
    for(int i = sFirst.length()-1; i>= 0 ; i--)
    {
        iAdd = 0;
        for(int j = sSecond.length() -1; j >= 0; j--)
        {
            sResult[i+j] = ((sFirst[i] - '0') * (sSecond[j] - '0') + sResult[i+j+1] - '0' )/10 + sResult[i+j];
            sResult[i+j+1] = ((sFirst[i] - '0') * (sSecond[j] - '0') + sResult[i+j+1] - '0' + iAdd) %10 + '0';
        }
    }
    int index = 0;
    while(index < sResult.length())
        if(sResult[index] != '0')
            break;
        else
            index++;    
    sResult = sResult.substr(index);
    return sResult;
}

string Factorial(int iNum)
{
    string sResult("1");
    if(iNum <= 1)
        return "1";
    else
    {
        std::ostringstream eam;
        eam << iNum;
        string sTmp = eam.str();
        sResult = Mulpti(Factorial(iNum-1),sTmp);
    }
    return sResult;
}

string FactorialV2(int iNum)
{
    string sResult("1");
    for(int index = 2; index <= iNum; index++)
    {
        std::ostringstream eam;
        eam << index;
        string sTmp = eam.str();
        sResult = Mulpti(sResult,sTmp);
    }
    return sResult;
}

// 兩個大數相乘
class Solution {
public:
    string multiply(string num1, string num2) {
        string res = "";
        int m = num1.size(), n = num2.size();
        vector<int> vals(m + n);
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1, sum = mul + vals[p2];
                vals[p1] += sum / 10;
                vals[p2] = sum % 10;
            }
        }
        for (int val : vals) {
            if (!res.empty() || val != 0) res.push_back(val + '0');
        }
        return res.empty() ? "0" : res;
    }
};

int main()
{
    cout << FactorialV2(10000) << endl;
    system("pause");
    return 0;
}
