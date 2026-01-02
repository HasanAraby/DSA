// b   problem name is easy longest increasing subsequence
#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()

const int N = 15, m = 1e5 + 10, mod = 1e9 + 7, mx = INT_MAX;
int dp[N], n, ar[N];

void test()
{
    cin >> n;
    // memset doesn't work properly you must do it handly
    // each problem has different intialization processes

    for (int i = 0; i < N; ++i)
        dp[i] = 1;

    for (int i = 0; i < n; ++i)
        cin >> ar[i];
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (ar[j] > ar[i])
                dp[j] = max(dp[j], dp[i] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp[i]);

    cout << ans << en;
}
int main()
{
    tasree int t = 1;
    // cin>>t;
    while (t--)
    {
        test();
    }

    return 0;
}
