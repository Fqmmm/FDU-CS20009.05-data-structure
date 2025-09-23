#include <iostream>
#include <string>
#include <stack>
using namespace std;

string decodeString(string s)
{
    stack<int> numStack;        // 数字栈
    stack<string> strStack;     // 字符串栈
    string currentStr = "";
    int currentNum = 0;

    for (char ch : s)
    {
        if ('0' <= ch && ch <= '9')
        {
            // 解析数字，注意处理多位数
            currentNum = currentNum * 10 + (ch - '0');
        }
        else if (ch == '[')
        {
            // 将当前状态入栈，为新层级做准备
            numStack.push(currentNum);
            strStack.push(currentStr);

            // 重置状态
            currentNum = 0;
            currentStr = ""; 
        }
        else if (ch == ']')
        {
            // 当前层级结束，开始解码

            // 重复次数
            int k = numStack.top();
            numStack.pop();

            // 构造重复后的字符串
            string tempStr = "";
            for (int i = 0; i < k; i++)
            {
                tempStr += currentStr;
            }

            // 与上一层的字符串拼接
            currentStr = strStack.top() + tempStr;
            strStack.pop();
        }
        else
        { 
            currentStr += ch;
        }
    }

    return currentStr;
}

int main()
{
    string encoded_str;
    cin >> encoded_str;
    string decoded_str = decodeString(encoded_str);
    cout << decoded_str << endl;

    return 0;
}