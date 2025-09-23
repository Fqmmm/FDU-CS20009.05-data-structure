#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> inputStream(n);
    vector<int> targetStream(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> inputStream[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> targetStream[i];
    }

    // 模拟水晶栈
    stack<int> crystalStack;

    // 理想序列中当前期望的符文（索引）
    int index = 0;

    // 遍历输入序列，模拟符文入栈
    for (int num : inputStream)
    {
        crystalStack.push(num);

        // 只要栈不为空，且栈顶元素是当前期望的符文，就出栈
        while (!crystalStack.empty() && crystalStack.top() == targetStream[index])
        {
            crystalStack.pop();
            index++; // 期望下一个理想符文
        }
    }

    // 如果所有输入符文处理完后，栈为空，则说明可以实现
    if (crystalStack.empty())
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}