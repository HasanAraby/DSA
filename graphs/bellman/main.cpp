#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define en '\n'
#define S second
#define F first
const int N = 3e5 + 10;
int n, m;
ll dis[N];
int to[N], from[N], w[N];
bool negLoop = 0;
// o(n*m)
//  dijkstra(mlogm) is better but :
//  1- you can check negative cycles
//  2- you can find shortest path with limited number of levels of edges // n = #wantedlevels
//  ** ifthere is a negative edge:
//  1- if directed maybe a negative cycle exist or not
//  2- if undirected a negative cycle exist
void BellmanFord(int src)
{
    for (int i = 0; i <= n; i++)
    {
        dis[i] = 1e12;
    }

    dis[src] = 0;

    for (int j = 1; j <= 2 * n; j++)
    {
        for (int i = 0; i < m; i++)
        {

            int u = from[i], v = to[i], weight = w[i];
            if (dis[u] + weight < dis[v])
            {
                if (j >= n)
                    negLoop = 1;
                dis[v] = dis[u] + weight;
            }
            // if undirected
            if (dis[v] + weight < dis[u])
            {
                if (j >= n)
                    negLoop = 1;
                dis[u] = dis[v] + weight;
            }
        }
    }
}

void test()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> from[i] >> to[i] >> w[i];
    }

    BellmanFord(1);

    for (int i = 1; i <= n; ++i)
        cout << dis[i] << " ";
    cout << en;
}

int main()
{
    int t = 1;
    // cin>>t;
    while (t--)
    {
        test();
    }

    return 0;
}
