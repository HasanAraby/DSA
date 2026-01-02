#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define en '\n'
#define S second
#define F first

const int N=1e3+10 , mod=1e9;
vector<int> adj[N];
int n,m,in[N],out[N];
vector<int>path;
void init()
{
    for(int i=0;i<N;i++)
    {
        in[i]=0 , out[i]=0 , adj[i].clear();
    }
    path.clear();
}

void EulerCircuit(int node)
{
    while(!adj[node].empty())
    {
        auto ch =adj[node].back();
        adj[node].pop_back();

        EulerCircuit(ch);
    }
        path.emplace_back(node);

}
int main()
{
   tasree
   int t;cin>>t;
while(t--)
{
    cin>>n>>m;
    init();
     for(int i=0;i<m;++i)
    {
        int u,v;
        cin>>u>>v;
        adj[u].emplace_back(v);
        in[v]++, out[u]++;

    }

    // check each node in degree == out degree

    for(int i=1;i<=n;i++)
        if(in[i]!=out[i])
        return cout<<"Not Possible\n", 0;

    EulerCircuit(1);

    // check connected

    if(int(path.size()) != m+1)
        return cout<<"Not Possible\n", 0;

      reverse(path.begin(),path.end());

      for(auto i:path)
        cout<<i<<" ";
      cout<<"Possible"<<en;

}


    return 0;
}
