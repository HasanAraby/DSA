#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define en '\n'
#define S second
#define F first
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int N = 1e3;
ll dis[N][N], n, m;
// n*n*n
// n * dijkstra (mlogm) is better but
// 1- this is so simple to code if fits in time constraints
// 2- you can exclude some vertices from shortest path  //if (k is unwanted) continue;
void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
}

void test()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = 1e12;
            if (i == j)
                dis[i][j] = 0;
        }
    int u, v, d;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> d;
        dis[u][v] = d;
        // if undirected
        dis[v][u] = d;
    }

    Floyd();

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cout << i << j << "  " << dis[i][j] << en;
}

int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        test();
    }
    return 0;
}
