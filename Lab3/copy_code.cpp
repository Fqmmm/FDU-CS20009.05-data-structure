#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// 判断是否为大写字母（非变量符号）
bool isUpper(char c)
{
    return c >= 'A' && c <= 'Z';
}

// 将字符串规范化：变量按首次出现顺序重新编号
string normalize(const string &s)
{
    string result;
    int varMap[26]; // 记录每个小写字母映射到的编号
    memset(varMap, -1, sizeof(varMap));
    int nextId = 0; // 下一个可用的变量编号

    for (char c : s)
    {
        if (isUpper(c))
        {
            result += c; // 大写字母直接保留
        }
        else
        {
            int idx = c - 'a';
            if (varMap[idx] == -1)
            {
                varMap[idx] = nextId++; // 首次出现，分配新编号
            }
            // 将编号转换为字符形式
            result += (char)('a' + varMap[idx]);
        }
    }
    return result;
}

int search(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();

    if (m == 0 || m > n)
        return 0;

    int i = 0;     // 超级字符串的指针
    int count = 0; // 匹配次数

    while (i < n)
    {
        int j = 0;     // 模式串的指针
        int start = i; // 当前子串的起始位置

        // 尝试匹配当前子串
        while (i < n && j < m && text[i] != '#')
        {
            if (text[i] == pattern[j])
            {
                i++;
                j++;
            }
            else
            {
                // 匹配失败，退出当前子串的匹配
                break;
            }
        }

        // 检查是否完全匹配
        if (j == m)
        {
            count++;
        }

        // 跳到下一个子串：跳过剩余字符和'#'分隔符
        while (i < n && text[i] != '#')
        {
            i++;
        }
        if (i < n && text[i] == '#')
        {
            i++; // 跳过'#'
        }
    }

    return count;
}

int main()
{
    string S, T;
    cin >> S >> T;

    int n = S.length();
    int m = T.length();

    if (m > n)
    {
        cout << 0 << endl;
        return 0;
    }

    // 规范化模式串T
    string normalizedT = normalize(T);

    // 构造超级字符串：用'#'连接所有规范化的子串
    string superString = "";
    for (int i = 0; i <= n - m; i++)
    {
        if (i > 0)
            superString += '#'; // 分隔符
        superString += normalize(S.substr(i, m));
    }

    int count = search(superString, normalizedT);

    cout << count << endl;

    return 0;
}