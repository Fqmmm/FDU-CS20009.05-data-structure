#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

// prim算法
int prim(vector<vector<int>>& graph, int n)
{
    vector<bool> visited(n, 0);
    vector<int> dist(n, INF);  // dist[i]表示节点i到已访问集合的最短距离
    int total_cost = 0;

    // 从节点0开始
    dist[0] = 0;

    // 需要添加n个节点
    for (int count = 0; count < n; count++)
    {
        // 找到距离已访问集合最近的未访问节点
        int min_dist = INF;
        int u = -1;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min_dist)
            {
                min_dist = dist[i];
                u = i;
            }
        }

        // 如果找不到下一个节点，说明图不连通
        if (u == -1 || min_dist == INF)
        {
            return -1;
        }

        // 将节点u加入已访问集合
        visited[u] = true;
        total_cost += min_dist;

        // 更新u的邻居节点到已访问集合的距离
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] && graph[u][v] < dist[v])
            {
                dist[v] = graph[u][v];
            }
        }
    }

    return total_cost;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
    {
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        // 处理重边：保留权重最小的边
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c);
    }

    int result = prim(graph, n);
    cout << result << endl;

    return 0;
}