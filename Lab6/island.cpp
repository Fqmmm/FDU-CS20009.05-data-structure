#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    bool map[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    // 计算岛屿的周长
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j])
            {
                if (i == 0 || map[i - 1][j] == 0) count++;      // 上
                if (i == m - 1 || map[i + 1][j] == 0) count++;  // 下
                if (j == 0 || map[i][j - 1] == 0) count++;      // 左
                if (j == n - 1 || map[i][j + 1] == 0) count++;  // 右
            }
        }
    }

    cout << count << endl;
    return 0;
}