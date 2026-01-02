#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define sz(s) (int)(s).size()
#define all(s) s.begin(), s.end()

void Speed()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

const int N = 1e6 + 5;
ll sum[N];
int n;

ll pre(int R)
{
    ll ans = 0;
    for (int i = R; i > 0; i -= i & -i)
    {
        ans += sum[i];
    }
    return ans;
}

void update(int j, int x)
{
    for (int i = j; i <= n; i += i & -i)
    {
        sum[i] += x;
    }
}

void solve()
{

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        update(i, x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        char ch;
        cin >> ch;
        if (ch == 'q')
        {
            int l, r;
            cin >> l >> r;
            cout << pre(r) - pre(l - 1) << '\n';
        }
        if (ch == 'u')
        {
            int i, x;
            cin >> i >> x;
            update(i, x);
        }
    }
}

int main()
{
    Speed();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}