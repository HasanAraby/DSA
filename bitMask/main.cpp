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

const int N=2e5+10,mod=1e9+7;

void test()
{
int n;
cin >> n;
int ar[n + 5], sum, tar, ans = 0;
cin >> tar;
for(int i = 0; i < n; ++i) cin >> ar[i];

for(int i = 0; i < (1 << n); ++i)
{
    sum = 0;
    for(int j = 0; j < n; ++j)
    {
        if((1 << j) & i) sum += ar[j];
    }
    if(sum == tar) ans++;
}
cout << ans << en;
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
