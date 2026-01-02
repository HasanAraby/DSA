// deal with components of only undirected graphs
// o(nlogn) or o((n + m) log n)
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
const int N = 1e4 + 10, mod = 1e9;
int p[N], sz[N];
bool iscycle = 0;
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
        int u, v;
        cin >> u >> v;
        connect(u, v);
    }
    set<int> ans;
    for (int i = 1; i <= n; i++)
        ans.insert(findparent(i));

    cout << (int)ans.size();
}

int main()
{
    tasree

        int t;
    cin >> t;
    while (t--)
    {
        test();
    }

    return 0;
}
