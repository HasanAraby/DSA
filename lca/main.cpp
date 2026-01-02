// like sparse table but on trees
// lowest common ancestor
// directed and undirected
// can work 0based and 1based (nodes)
// static range query using sparse table but on trees.
// time comlexity: o(n)
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ld long double
const int N = 3e5 + 5, M = 55, MOD = 1e9 + 7, MX = INT_MAX;

int sp[N][25], op[N][25], lvl[N], n;
vector<pair<int, int>> g[N];
int merge(int a, int b)
{
    return max(a, b);
}
void dfs(int node, int par, int w)
{
    lvl[node] = lvl[par] + 1;
    sp[node][0] = par;
    op[node][0] = w;

    for (int j = 1; j <= 20; ++j)
    {
        sp[node][j] = sp[sp[node][j - 1]][j - 1];
        op[node][j] = merge(op[node][j - 1], op[sp[node][j - 1]][j - 1]);
    }
    for (auto ch : g[node])
    {
        if (ch.F == par)
            continue;
        dfs(ch.F, node, ch.S);
    }
}

// return the kth ancestor of node u in o(log) using binary lifting
pair<int, int> getKthAncestor(int u, int k)
{
    int opp = 0;
    // int opp= MX;
    for (int i = 20; i >= 0; i--)
    {
        if ((1 << i) <= k)
        {
            opp = merge(opp, op[u][i]);
            u = sp[u][i];
            k -= (1 << i);
        }
    }
    return {u, opp};
}

// return lowest common ancestor between u,v;
pair<int, int> getLCA(int u, int v)
{
    if (lvl[u] < lvl[v])
        swap(u, v);

    int diff = lvl[u] - lvl[v];
    auto ret = getKthAncestor(u, diff);
    u = ret.F;
    int opp = ret.S;
    if (u == v)
        return {u, opp};
    for (int i = 20; i >= 0; --i)
    {
        if (sp[u][i] != sp[v][i])
        {
            opp = merge(opp, op[u][i]);
            opp = merge(opp, op[v][i]);
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    opp = merge(op[v][0], opp);
    opp = merge(op[u][0], opp);
    return {sp[v][0], opp};
}

void test()
{
    cin >> n;
    for (int i = 0; i <= n; ++i)
        g[i].clear();

    int q, u, v, m, x;

    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 1; j <= m; ++j)
        {
            cin >> x;
            g[i].push_back({x, 0});
            g[x].push_back({i, 0});
        }
    }

    // make sure to start dfs from node and par is the same node
    dfs(0, 0, 0);

    cin >> q;
    while (q--)
    {
        cin >> u >> v;
        cout << getLCA(u, v).F << en;
    }
}
int main()
{
    tasree int t = 1;
    // cin>>t;
    while (t--)
    {
        test();
    }
    return 0;
}
