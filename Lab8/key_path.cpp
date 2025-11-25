#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> matrix;
vector<int> TE, TL;
int n;

int getWeight(int i, int j)
{
    return matrix[i][j];
}

// DFS找关键路径
bool findPath(int u, vector<int>& path)
{
    path.push_back(u);

    if (u == n - 1)
    {
        return true; // 到达终点
    }

    for (int v = 0; v < n; v++)
    {
        if (matrix[u][v] > 0)
        {
            if (TE[u] == TL[u] && TE[v] == TL[v] && TE[u] + matrix[u][v] == TE[v])
            {
                if (findPath(v, path))
                {
                    return true;
                }
            }
        }
    }

    path.pop_back();
    return false;
}

int main()
{
    int m;
    cin >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++)
    {
        matrix[i].resize(n);
    }

    // 输入
    for (int i = 0; i < m; i++)
    {
        int row, col, w;
        cin >> row >> col >> w;
        matrix[row][col] = w;
    }

    // 计算入度，用于拓扑排序
    vector<int> inDegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] > 0)
            {
                inDegree[j]++;
            }
        }
    }

    // 拓扑排序，获取事件的处理顺序
    queue<int> q;
    vector<int> topoOrder; // 拓扑序列
    vector<int> tempInDegree = inDegree; // 临时入度数组

    for (int i = 0; i < n; i++)
    {
        if (tempInDegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v = 0; v < n; v++)
        {
            if (matrix[u][v] > 0)
            {
                tempInDegree[v]--;
                if (tempInDegree[v] == 0)
                {
                    q.push(v);
                }
            }
        }
    }

    // 计算最早发生时间(TE)
    TE.resize(n, 0);
    for (int i = 0; i < topoOrder.size(); i++)
    {
        int u = topoOrder[i];
        for (int v = 0; v < n; v++)
        {
            if (matrix[u][v] > 0)
            {
                // 事件v的最早发生时间 = max(所有前驱事件u的TE + 活动持续时间)
                TE[v] = max(TE[v], TE[u] + matrix[u][v]);
            }
        }
    }

    // 计算最迟发生时间(TL)
    TL.resize(n, TE[n - 1]); // 初始化为终点事件的最早发生时间
    // 按拓扑逆序计算
    for (int i = topoOrder.size() - 1; i >= 0; i--)
    {
        int u = topoOrder[i];
        for (int v = 0; v < n; v++)
        {
            if (matrix[u][v] > 0)
            {
                // 事件u的最迟发生时间 = min(所有后继事件v的TL - 活动持续时间)
                TL[u] = min(TL[u], TL[v] - matrix[u][v]);
            }
        }
    }

    // 找关键路径：从起点到终点，选择TE==TL的事件
    vector<int> criticalPath;
    findPath(0, criticalPath);

    // 输出结果
    for (int i = 0; i < n; i++)
    {
        cout << TE[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << TL[i];
        if (i < n - 1) cout << " ";
    }
    cout << endl;

    for (int i = 0; i < criticalPath.size(); i++)
    {
        cout << criticalPath[i];
        if (i < criticalPath.size() - 1) cout << " ";
    }
    cout << endl;

    cout << TE[n - 1] << endl;

    return 0;
}