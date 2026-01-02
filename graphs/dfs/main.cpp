// deal with components of graph
#pragma GCC optimze "trapv"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e4+10,mod=1e9;
vector<int> ar[N];

int vis[N];

void dfs(int cur)
{
    vis[cur]=1;
    for(auto x:ar[cur])
    {
        if(vis[x]==0) dfs(x);

        else if(vis[x]==1) continue;
    }

}


void init(int n)
{
    for(int i=0;i<=n;i++)
    {
        ar[i].clear();vis[i]=0;
    }


}

void test()
{
 int n;cin>>n;
 {
     int x,y;
     cin>>x>>y;
     ar[x].push_back(y);
     ar[y].push_back(x);
 }
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


