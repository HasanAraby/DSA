// bfs move level by level
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
const int N = 1e5 + 10, mod = 1e9;
int cost[N];
vector<int> adj[N];
queue<int> q;
void init(int n)
{
    for (int i = 1; i <= n; i++)
        cost[i] = 1e9;
}
// o(n + m)
// the shortest path between one node and all nodes based on levels
void bfs(int stNode)
{
    cost[stNode] = 0;
    q.push(stNode);
    while (q.size())
    {
        int cur = q.front();
        q.pop();
        int nxtCost = cost[cur] + 1;
        for (auto ch : adj[cur])
        {
            if (nxtCost < cost[ch])
            {
                q.push(ch);
                cost[ch] = nxtCost;
            }
        }
    }
}
int main()
{
    tasree int n, m;
    cin >> n >> m;
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    init(n);
    bfs(1);

    for (int i = 1; i <= n; i++)
        cout << "cost from 1 to " << i << " = " << cost[i] << en;
    return 0;
}
