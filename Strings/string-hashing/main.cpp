// there is single and triple hash but this is double hash , the more you hash you decrease probability of collision or duplicates
// base must be > max digit
// string1==string2 o(n) => hash1==hash2 o(1)
// can get hash(substring) 0(1)
//  MODInverse of x = x^(MOD-2); x must be relatively prime =>(gcd(x,MOD)=1) with MOD so base must be prime
// above case will be clear in substring hash while dividing over pw[L] which is base^(index)
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
const int N = 1e6 + 10, M = 55, MOD = 1e9 + 7, MX = INT_MAX, base = 31, base2 = 37;
int pw[N], inv[N], pw2[N], inv2[N];
int add(int a, int b)
{
    return (0LL + a + b + MOD) % MOD;
}

int mul(int a, int b)
{
    return (1LL * a * b) % MOD;
}

int fastPow(int b, int p)
{
    if (!p)
        return 1;
    int rqm = fastPow(b, p >> 1);
    rqm = mul(rqm, rqm);
    if (1 & p)
        rqm = mul(rqm, b);
    return rqm;
}
void pre()
{
    pw[0] = 1;
    inv[0] = 1;
    pw2[0] = 1;
    inv2[0] = 1;
    for (int i = 1; i < N; ++i)
    {
        pw[i] = mul(base, pw[i - 1]);
        inv[i] = fastPow(pw[i], MOD - 2);

        pw2[i] = mul(base2, pw2[i - 1]);
        inv2[i] = fastPow(pw2[i], MOD - 2);
    }
}
int pref[N], pref2[N];
// o(n)
void generateHash(string &str)
{
    for (int i = 0; i < sz(str); ++i)
    {
        int idx = str[i] - 'a' + 1;
        pref[i] = mul(idx, pw[i]);
        if (i)
            pref[i] = add(pref[i], pref[i - 1]);

        pref2[i] = mul(idx, pw2[i]);
        if (i)
            pref2[i] = add(pref2[i], pref2[i - 1]);
    }
}

pair<int, int> getHash(string &str)
{
    int hashValue = 0, hashValue2 = 0;
    for (int i = 0; i < sz(str); ++i)
    {
        int idx = str[i] - 'a' + 1;
        hashValue = add(hashValue, mul(idx, pw[i]));
        hashValue2 = add(hashValue2, mul(idx, pw2[i]));
    }
    return {hashValue, hashValue2};
}

// substring
pair<int, int> getHash(int l, int r)
{
    int ret = pref[r];
    if (l)
        ret = add(ret, -pref[l - 1]);
    ret = mul(ret, inv[l]);

    int ret2 = pref2[r];
    if (l)
        ret2 = add(ret2, -pref2[l - 1]);
    ret2 = mul(ret2, inv2[l]);

    return {ret, ret2};
}

void test()
{

    string s;
    cin >> s;
    generateHash(s);
}
int main()
{
    tasree
    pre();
    int t = 1;
    // cin>>t;
    while (t--)
    {
        test();
    }
    return 0;
}
