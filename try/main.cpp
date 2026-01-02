#pragma GCC optimze "trapv"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())

const int N = 1e3 + 5, mod = 1e9 + 7;
int dp[N][N][5], ds[N], dir[N], n , m, x;
int solve(int cur, int cq)
{
    // cout << cur << ' ' << ds[cq] << ' ' << dir[cq] << ' ' << cq << en;
    if(cq == m + 1) {return 1 << (cur - 1);}

    int &ret = dp[cur][ds[cq]][dir[cq]];
    if(~ret) return ret;

    int rcur = (cur + ds[cq] - 1) % n + 1;
    int lcur = (cur - ds[cq] - 1 + n) % n + 1;

    ret = 0;

    if(!dir[cq]) ret |= solve(rcur, cq + 1);
    else if(dir[cq] == 1)
        ret |= solve(lcur, cq + 1);
    else
    {
      ret |= solve(rcur, cq + 1);
      ret |= solve(lcur, cq + 1);
    }

    return ret;
}
void test()
{
    memset(dp, -1, sizeof dp);
   cin >> n >> m >> x;
   char ch;

   for(int i = 1; i <= m; ++i){
    cin >> ds[i] >> ch;
    if(ch == '1') dir[i] = 1;
    else if(ch == '0') dir[i] = 0; //clockwise
    else dir[i] = 2;
   }

   int ans = solve(x, 1);
   cout << __builtin_popcount(ans) << en;
   int c = 1;
   while(ans){
    if(1 & ans) cout << c << ' ';
    ans = ans >> 1;
    c++;
   }
   cout << en;
}

int main()
{
tasree

int t = 1;
cin >> t;
while(t--)
{
test();
}

return 0;
}
