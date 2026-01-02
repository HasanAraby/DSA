#include <bits/stdc++.h>
using namespace std;
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define en '\n'
#define F first
#define S second

const int N=1e2+5,M=1e2+5,mod=1e9+7;

void test()
{
int ar[N][M],px[N][M];

int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>ar[i][j];

 for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        px[i][j]=ar[i][j]+px[i-1][j]+px[i][j-1]-px[i-1][j-1];

    cout<<px[3][3];
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
