// complexity nlog(n) or o((n + m) logn)
// undirected graph
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define siz(x) (int)x.size()
#define en '\n'

const int N = 1e4 + 10, mod = 1e9;
int p[N], sz[N];
bool iscycle = 0;
vector<pair<int, pair<int, int>>> edges;
int n, m;
void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        sz[i] = 1;
    }
}
// log(n)
int findparent(int x)
{
    if (p[x] == x)
        return x;
    return p[x] = findparent(p[x]);
}

void connect(int u, int v)
{
    u = findparent(u);
    v = findparent(v);

    if (u == v)
    {
        iscycle = 1;
        return;
    }

    if (sz[u] < sz[v])
    {
        p[u] = v, sz[v] += sz[u];
    }

    else
    {
        p[v] = u, sz[u] += sz[v];
    }
}

bool isconnected(int u, int v)
{
    return (findparent(u) == findparent(v));
}

void test()
{
    cin >> n >> m;
    init(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        edges.push_back({c, {u, v}});
    }
    sort(all(edges));
    int ans = 0;

    for (auto ed : edges)
    {
        if (isconnected(ed.S.F, ed.S.S))
            continue;
        else
            ans += ed.F, connect(ed.S.S, ed.S.F);
    }

    cout << ans << en;
}

// min spanning tree is applied by kruskal approach using dsu, or prim approach using greedy
// this file is kruksal o((n + m) logn)
// kruskal use n-1 edges from graph to make it tree with min sum of edges cost

int main()
{
    tasree

        int t = 1;
    cin >> t;
    while (t--)
    {
        test();
    }

    return 0;
}
