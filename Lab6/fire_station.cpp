#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int graph[n][n]; // graph[i][j]是直接道路的长度
    int dis[n][n];   // dis[i][j]是i到j最短路径的长度

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int val;
            cin >> val;
            graph[i][j] = val;

            // 处理无直接道路的情况
            if (i == j)
            {
                dis[i][j] = 0;  // 自己到自己距离为0
            }
            else if (val == 0)
            {
                dis[i][j] = 1e9; // 无直接道路，设为无穷大
            }
            else
            {
                dis[i][j] = val; // 有直接道路
            }
        }
    }

    // 计算最短路径
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    // 找到到其他街区最短路径的最大值
    int path[n];
    for (int i = 0; i < n; i++)
    {
        int len = 0;
        for (int j = 0; j < n; j++)
        {
            if (len < dis[i][j])
                len = dis[i][j];
        }
        path[i] = len;
    }

    // 最大值的最小值
    int index = 0;
    int min_val = 100000;
    for (int i = 0; i < n; i++)
    {
        if (path[i] < min_val)
        {
            min_val = path[i];
            index = i;
        }
    }

    cout << index << endl;
}