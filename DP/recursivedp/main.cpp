//big(o)size of dp array * number of call inside solve function
#pragma GCC optimze "trapv"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
//lcs problem in sheet need build because it needs path but not all problems of dp need build
const int N=3e3+5, m=1e5+10,mod=1e9+7;
int dp[N][N];
string a,b;
int solve(int i, int j)
{
    if(i==int(a.size()) || j==int(b.size()))
        return 0;

    int &ret=dp[i][j];
    if(~ret)
        return ret;

    if(a[i]==b[j])
        ret=solve(i+1,j+1)+1;
    else
        ret=max(solve(i+1,j),solve(i,j+1));

    return ret;
}

void build(int i, int j)
{
    if(i==int(a.size()) || j==int(b.size()))
        return;

    if(a[i]==b[j])
    {
        cout<<a[i];
         build(i+1,j+1);
    }
    else
    {
        if(solve(i+1,j)>solve(i,j+1))
            build(i+1,j);
        else
            build(i,j+1);
    }
}

void test()
{
memset(dp,-1,sizeof dp);
cin>>a>>b;

build(0,0);
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
