#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 边的结构：邻接节点和权值
struct Edge
{
    int to;      // 目标节点
    long long w; // 边权
    Edge(int t, long long weight) : to(t), w(weight) {}
};

// 优先队列中的元素：边权和目标节点
struct Node
{
    long long weight; // 边权
    int v;            // 节点编号
    Node(long long w, int vertex) : weight(w), v(vertex) {}

    // 优先队列默认是大根堆，重载运算符使其变为小根堆
    bool operator>(const Node& other) const
    {
        return weight > other.weight;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    // 邻接表存储图
    vector<vector<Edge>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // 无向图，存储双向边
        graph[u].push_back(Edge(v, w));
        graph[v].push_back(Edge(u, w));
    }

    // Prim算法
    vector<bool> visited(n + 1, false);  // 标记节点是否已加入生成树
    priority_queue<Node, vector<Node>, greater<Node>> pq; // 最小堆
    long long totalWeight = 0; // 最小生成树的总权值

    // 从节点1开始
    visited[1] = true;
    // 将节点1的所有邻边加入优先队列
    for (const Edge& e : graph[1])
    {
        pq.push(Node(e.w, e.to));
    }

    int edgeCount = 0; // 已加入生成树的边数

    // 当还需要边且优先队列不为空时继续
    while (edgeCount < n - 1 && !pq.empty())
    {
        Node current = pq.top();
        pq.pop();

        // 如果目标节点已访问，跳过
        if (visited[current.v])
        {
            continue;
        }

        // 将该节点加入生成树
        visited[current.v] = true;
        totalWeight += current.weight;
        edgeCount++;

        // 将新节点的所有邻边加入优先队列
        for (const Edge& e : graph[current.v])
        {
            if (!visited[e.to])
            {
                pq.push(Node(e.w, e.to));
            }
        }
    }

    cout << totalWeight << endl;

    return 0;
}
