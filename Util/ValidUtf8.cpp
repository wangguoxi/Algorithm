/**
 * 验证是否为utf8编码
 */
/**
UTF-8 中的一个字符可能的长度为 1 到 4 字节，遵循以下的规则：
对于 1 字节的字符，字节的第一位设为0，后面7位为这个符号的unicode码。
对于 n 字节的字符 (n > 1)，第一个字节的前 n 位都设为1，第 n+1 位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。
这是 UTF-8 编码的工作方式：

   Char. number range  |        UTF-8 octet sequence
      (hexadecimal)    |              (binary)
   --------------------+---------------------------------------------
   0000 0000-0000 007F | 0xxxxxxx
   0000 0080-0000 07FF | 110xxxxx 10xxxxxx
   0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
   0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
给定一个表示数据的整数数组，返回它是否为有效的 utf-8 编码。
注意:
输入是整数数组。只有每个整数的最低 8 个有效位用来存储数据。这意味着每个整数只表示 1 字节的数据。

示例 1:

data = [197, 130, 1], 表示 8 位的序列: 11000101 10000010 00000001.

返回 true 。
这是有效的 utf-8 编码，为一个2字节字符，跟着一个1字节字符。
示例 2:

data = [235, 140, 4], 表示 8 位的序列: 11101011 10001100 00000100.

返回 false 。
前 3 位都是 1 ，第 4 位为 0 表示它是一个3字节字符。
下一个字节是开头为 10 的延续字节，这是正确的。
但第二个延续字节不以 10 开头，所以是不符合规则的。
这样我们就会很方便的来处理，整个整数数组中，都是从高到底来处理的，而且每个元素都表示一个字节的值
 */
#include <iostream>
#include <vector>
using namespace std;

bool isValidUTF8(const vector<int>& vInt)
{
    // 按照规定需要把1全部按序消灭
    int iLefNum = 0;
    for(int index = 0 ; index < vInt.size() ; index++)
    {
        if(iLefNum > 0) // 需要保证按序
        {
            if(vInt[index] >> 7)
            {
                iLefNum--;
            }
            else
            {
                break;
            }
        }
        else
        {
            // 判断当前自己高位有多少个1
            int iTmp = vInt[index];
            while((iTmp & (0x80 + 0x40)) == 0x80) 
            {
                iLefNum++;
                iTmp = iTmp << 1;
            }
            iLefNum = iLefNum > 0 ? iLefNum -1 : iLefNum; 
        }
    }
    cout << iLefNum << endl;
    return iLefNum == 0 ? true : false;
}

int main()
{
    vector<int> vInt;
    vInt.push_back(235);
    vInt.push_back(140);
    vInt.push_back(4);
    cout << isValidUTF8(vInt);
    system("pause");
    return 0;
}