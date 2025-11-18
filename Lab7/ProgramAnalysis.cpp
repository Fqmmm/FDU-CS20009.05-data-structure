#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 并查集类
class UnionFind
{
public:
    vector<int> parent;

    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    // 查找根节点，带路径压缩
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // 合并两个集合
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootX] = rootY;
        }
    }

    // 判断两个元素是否在同一集合
    bool isSame(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        // 存储所有约束条件
        vector<int> vi(n), vj(n), ve(n);
        unordered_map<int, int> idMap; // 离散化映射
        int idCounter = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> vi[i] >> vj[i] >> ve[i];

            // 离散化
            if (idMap.find(vi[i]) == idMap.end())
            {
                idMap[vi[i]] = idCounter++;
            }
            if (idMap.find(vj[i]) == idMap.end())
            {
                idMap[vj[i]] = idCounter++;
            }
        }

        UnionFind uf(idCounter);

        // 处理所有相等约束
        for (int i = 0; i < n; i++)
        {
            if (ve[i] == 1)
            {
                uf.unite(idMap[vi[i]], idMap[vj[i]]);
            }
        }

        // 检查所有不等约束
        bool valid = true;
        for (int i = 0; i < n; i++)
        {
            if (ve[i] == 0)
            {
                if (uf.isSame(idMap[vi[i]], idMap[vj[i]]))
                {
                    valid = false;
                    break;
                }
            }
        }

        cout << (valid ? "YES" : "NO") << "\n";
    }

    return 0;
}
