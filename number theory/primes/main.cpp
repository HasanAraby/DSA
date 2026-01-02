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

const int N = 1e5 + 100, mod = 1e9 + 7;
// check is it prime in o(sqrt(n))
bool prime(int n)
{
    for (ll i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}
//////////////////////////////////////
// to get divisors in o (sqrt(n))
vector<ll> getDivisors(ll n)
{
    vector<ll> divisors;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
            if (i != n / i)
                divisors.push_back(n / i);
        }
    }
    return divisors;
}
////////////////////////////////////
// to get prime factors in o(sqrt(n))

vector<pair<ll, ll>> primeFactors(ll n)
{
    vector<pair<ll, ll>> pFactors;
    for (ll i = 2; i * i <= n; ++i)
    {
        ll c = 0;
        while (n % i == 0)
        {
            c++;
            n /= i;
        }
        if (c)
            pFactors.push_back({i, c});
    }
    if (n > 1)
        pFactors.push_back({n, 1});
    return pFactors;
}

///////////////////////////////////
// big o(n log(log n))
vector<bool> seive(int n)
{
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i <= n; ++i)
    {
        if (isPrime[i])
            for (ll j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
    }
    return isPrime;
}

///////////////////////////////////
// sieve optimization
// big o(sqrt(n) log(log n))
vector<bool> optimizedSeive(int n)
{
    vector<bool> isPrime(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (ll i = 2; i * i <= n; ++i)
    {
        if (isPrime[i])
            for (ll j = 2 * i; j <= n; j += i)
                isPrime[j] = 0;
    }
    return isPrime;
}

void test()
{
    vector<bool> s = seive(100);
    vector<bool> sopt = optimizedSeive(100);

    for (auto i : s)
        cout << i << ' ';
    cout << en << en;
    for (auto i : sopt)
        cout << i << ' ';
}
int main()
{
    tasree int t = 1;
    cin >> t;
    while (t--)
    {
        test();
    }
    return 0;
}
