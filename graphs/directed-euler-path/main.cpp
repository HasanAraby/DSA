#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define en '\n'
#define S second
#define F first

const int N=2e5+10 , mod=1e9;
vector<int> adj[N];
int n,m,in[N],out[N];
vector<int>path;
void EulerPath(int node)
{
    while(!adj[node].empty())
    {
        auto ch =adj[node].back();
        adj[node].pop_back();

        EulerPath(ch);
    }
        path.emplace_back(node);

}
int main()
{
    tasree
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        in[v]++, out[u]++;

    }

    // check each node in degree == out degree

    for(int i=2;i<n;i++)
        if(in[i]!=out[i])
             return cout<<"IMPOSSIBLE\n" , 0;
//except two nodes
//             start node        end node
        if(out[1]!=in[1]+1 || in[n]!=out[n]+1)
           return cout<<"IMPOSSIBLE\n" , 0;

           //note: start=1, end=n, iterate 2:n-1 .
    EulerPath(1);

    // check connected

    if(int(path.size()) != m+1)
      return cout<<"IMPOSSIBLE\n" , 0;

      reverse(path.begin(),path.end());

      for(auto i:path)
        cout<<i<<" ";
      cout<<en;

    return 0;
}
