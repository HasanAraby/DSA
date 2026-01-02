
#pragma GCC optimze "trapv"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
const int N=1e5+5, m=2e5+10,mod=1e9;
int dp[25][1<<21];
int n;
vector<int>g[m];
int rec(int node,int msk)
{
  if(node==n)
  {
      if(msk==(1<<n)-1)
        return 1;
      return 0;
  }
  int &ret=dp[node][msk];
  if(~ret)
    return ret;
  ret=0;
  for(auto ch:g[node])
  {
      if(msk&(1<<(ch-1)))
        continue;
      ret=(ret+rec(ch,msk|(1<<(ch-1))))%mod;
  }
  return ret;
}
void test()
{
    //input
    memset(dp,-1,sizeof dp);
   rec(1,1);
}

int main(){
tasree
int t=1;
//cin>>t;
while(t--)
{
  test();
}

return 0;
}

