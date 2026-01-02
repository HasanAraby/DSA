#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ld long double
const int N = 5e3 + 5, M = 55, MOD = 1e9 + 7, MX = INT_MAX;

const int mod = 1e9 + 7;

typedef vector<ll> Row;
typedef vector<Row> Matrix;

Matrix Zero(int n, int m)
{
    return Matrix(n, Row(m));
}

Matrix Identity(int n)
{
    Matrix res = Zero(n, n);
    for (int i = 0; i < n; i++)
    {
        res[i][i] = 1;
    }
    return res;
}

Matrix Multiply(const Matrix &a, const Matrix &b)
{
    Matrix res = Zero(sz(a), sz(b[0]));
    for (int i = 0; i < sz(a); i++)
    {
        for (int j = 0; j < sz(b[0]); j++)
        {
            for (int k = 0; k < sz(b); k++)
            {
                res[i][j] += a[i][k] * b[k][j];
                res[i][j] %= mod;
            }
        }
    }
    return res;
}

Matrix Power(const Matrix &base, ll k)
{
    if (k == 0)
        return Identity(sz(base));
    if (k & 1)
        return Multiply(base, Power(base, k - 1));
    return Power(Multiply(base, base), k >> 1);
}

// fibonacci example
void solve()
{
    ll n;
    cin >> n;
    Matrix T = Zero(2, 2);
    T = {{0, 1}, {1, 1}};
    T = Power(T, n);
    Matrix init = Zero(2, 2);
    init = {{0, 1}};
    init = Multiply(init, T);
    cout << init[0][0] << '\n';
}

int main()
{
    tasree;
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
    return 0;
}