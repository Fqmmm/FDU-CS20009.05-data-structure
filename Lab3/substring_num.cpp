#include <iostream>
#include <vector>
#include <string> // 建议包含 <string> 头文件

using namespace std;

void getNext(string p, vector<int> &next)
{
    int len = p.length();
    next.resize(len + 1); // next 数组的长度需要比模式串多 1
    next[0] = -1;
    int k = -1;
    int j = 0;
    while (j < len)
    {
        if (k == -1 || p[j] == p[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int main()
{
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    // 处理特殊情况
    if (lenA < lenB) 
    {
        cout << 0;
        return 0;
    }

    // 构造 next 数组
    vector<int> next;
    getNext(B, next);

    int i = 0, j = 0, count = 0;
    while (i < lenA)
    {
        if (j == -1 || A[i] == B[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j]; 
        }

        // 匹配成功一次
        if (j == lenB)
        {
            count++;
            j = next[j];
        }
    }

    cout << count;
    return 0;
}