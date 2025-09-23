#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums;
    int num;
    int len = 0;
    // 输入数字
    while (cin >> num) {
        nums.push_back(num);
        len++;
        // 检查下一个字符是否为换行符
        if (cin.peek() == '\n') {
            break;
        }
    }

    // 存储下一个最大元素
    vector<int> res(len, -1);    
    for (int i = 0; i < len; i++)
    {
        for (int j = 1; j < len; j++)
        {
            int index = (i + j) % len;
            if (nums[index] > nums[i])
            {
                res[i] = nums[index];
                break;
            } 
        }
    }

    // 输出
    for (int i = 0; i < len; i++)
    {   
        cout << res[i] << " ";
    }

    return 0;
}