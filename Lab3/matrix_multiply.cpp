#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// 安全取模，保证非负
inline long long mod(long long x)
{
    return (x % MOD + MOD) % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, p, m;
    cin >> n >> p >> m;

    // 用二维 vector 存储 A、B、C
    vector<vector<long long>> A(n, vector<long long>(p));
    vector<vector<long long>> B(p, vector<long long>(m));
    vector<vector<long long>> C(n, vector<long long>(m, 0));

    // 输入 A
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            long long x;
            cin >> x;
            A[i][j] = mod(x);
        }
    }

    // 输入 B
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long x;
            cin >> x;
            B[i][j] = mod(x);
        }
    }

    // 转置 B 为 B_T
    vector<vector<long long>> B_T(m, vector<long long>(p));
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B_T[j][i] = B[i][j];
        }
    }

    // 矩阵乘法
    long long limit = 8LL * MOD;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long sum = 0;
            for (int k = 0; k < p; k++)
            {
                sum += A[i][k] * B_T[j][k];
                if (sum >= limit)
                    sum %= MOD; // 延迟取模
            }
            C[i][j] = sum % MOD;
        }
    }

    // 输出
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
