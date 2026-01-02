#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define en '\n'
#define S second
#define F first

const int N=2e5+10 , mod=1e9;
vector<pair<int,int>> adj[N];
int n,m,vis[N];
vector<int>path;
void EulerCircuit(int node)
{
    while(!adj[node].empty())
    {
        auto ch =adj[node].back();
        adj[node].pop_back();
        int edgeidx=ch.S , nxt=ch.F;
        if(vis[edgeidx])
            continue;
        vis[edgeidx]=1;
        EulerCircuit(nxt);
    }
    path.emplace_back(node);
}
void test()
{
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v,i);
        adj[v].emplace_back(u,i);
    }

    // check each node has even degree

    for(int i=1;i<=n;i++)
        if(int(adj[i].size())%2)
         return cout<<"IMPOSSIBLE\n",void();
    EulerCircuit(1);

    // check connected

    if(int(path.size()) != m+1)
               return cout<<"IMPOSSIBLE\n",void();

      for(auto i:path)
        cout<<i<<" ";
      cout<<en;
}
int main()
{
tasree
int t=1;
cin>>t;
while(t--)
{
    test();
}

return 0;
}
