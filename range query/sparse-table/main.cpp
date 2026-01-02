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
#define ld long double
//static range query
//0based
const int N=1e6+10,M=55,MOD=1e9+7,MX=INT_MAX,base=31,base2=37;
int sp[N][25], lg[N], a[N], n;
int merge(int a, int b)
{
    return min(a, b);
}
//o(nlog)
void build()
{
    lg[0] = lg[1] = 0;
    for(int i = 2; i <= n; ++i)
        lg[i] = lg[i>>1] + 1;

    for(int i = 0; i < n; ++i)
        sp[i][0] = a[i];

    for(int j = 1; j < 21; ++j) //(1<<20) fit the max expected array size 1e6
        for(int i = 0; i + (1<<j) <= n; i++)
        sp[i][j] = merge(sp[i][j-1], sp[i + (1<<(j - 1))][j - 1]);
}
//o(log)    sum,xor
int queryLog(int l, int r)
{
    int ret = 0;
    for(int j = 20; j >= 0; j--)
    {
        if(l + (1<<j) - 1 <= r)
        {
            ret = merge(ret , sp[l][j]);
            l += 1<<j;
        }
    }
    return ret;
}
//o(1)  max,min,gcd
int query1(int l,int r)
{
    int k = lg[r - l + 1];
    return merge(sp[l][k], sp[r - (1<<k) + 1][k]);
}
void test()
{
cin >> n;
for(int i = 0; i < n; ++i)
    cin >> a[i];
    build();
int q;cin >> q;
while(q--)
{
    int l, r;
    cin >> l >> r;
    cout << query1(l,r) << en;
}
}
int main(){
tasree
int t = 1;
//cin>>t;
while(t--)
{
test();
}
return 0;
}
