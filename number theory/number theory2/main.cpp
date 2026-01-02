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

const int N = 1e3 + 200, mod = 1e9 + 7;
ll fact[N];

// gcd o(logn)  = builin __gcd o(logn) no difference
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

// lowest common multiple o(loga) or o(logb) because it is based on gcd
// instead of o(a*b)
// lcm(6, 2) = 12
ll lcm(ll a, ll b)
{
	return a / __gcd(a, b) * b;
}

// o(logb)
// instead of o(b)
ll fastPower(ll a, ll b)
{
	if (!b)
		return 1;

	ll bi = fastPower(a % mod, b >> 1) % mod;
	return ((bi % mod * bi % mod) % mod * ((b & 1) ? a % mod : 1) % mod) % mod;
}

// If the mod is prime, there is another faster method to calculate the mod inverse in O(log(m)) using Fermats�s little theorem.
ll modInverse(ll a, ll m)
{
	int g = __gcd(a, m);
	if (g != 1)
		return -1; // there is no modinverse
	// If a and m are relatively prime, then modulo
	// inverse is a^(m-2) mode m
	return fastPower(a, m - 2);
}

ll nPr(ll n, ll r)
{ // modInverse
	return (fact[n] % mod * fastPower(fact[n - r] % mod, mod - 2) % mod) % mod;
}

ll nCr(ll n, ll r)
{ // modInverse
	return (fact[n] % mod * fastPower(fact[r] % mod * fact[n - r] % mod, mod - 2) % mod) % mod;
}
void test()
{
}
int main()
{
	tasree
		fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i] = (fact[i - 1] % mod * i % mod) % mod;
	int t = 1;
	cin >> t;
	// pre();
	while (t--)
	{
		test();
	}
	return 0;
}
