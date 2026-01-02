// shortest path between one node and all other nodes in a weighted graph directed and undirected
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

const int N = 1e5 + 10, mod = 1e9;
vector<pair<int, int>> adj[N];
int cost[N];
int n, m;
// o(n+m)*log(m)  || m log(m)
void dijkstra(int src)
{
    for (int i = 1; i <= n; i++)
        cost[i] = 1e9;
    cost[src] = 0;

    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while (pq.size())
    {
        int node = pq.top().S, curcost = -pq.top().F;
        pq.pop();
        if (cost[node] < curcost)
            continue;
        for (auto ch : adj[node])
        {
            int child = ch.F, edgecost = ch.S;
            int nxcost = edgecost + curcost;
            if (nxcost < cost[child])
            {
                cost[child] = nxcost;
                pq.push({-nxcost, child});
            }
        }
    }
}

void test()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
        cout << i << " " << cost[i] << " " << en;
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
