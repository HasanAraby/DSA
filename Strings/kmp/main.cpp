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
const int N = 2e5 + 5, M = 55, MOD = 1e9 + 7, MX = INT_MAX, base = 31, base2 = 37;
// return vector each value in it equals to the longest prober sufix from this pos and is a prober prefix
// prober means not the full length
// o(n) or o(2*n)
vector<int> kmp(string str)
{
    int len = sz(str);
    vector<int> fail(len, 0);
    for (int i = 1; i < len; ++i)
    {
        int j = fail[i - 1];
        while (j > 0 and str[i] != str[j])
            j = fail[j - 1];

        if (str[i] == str[j])
            j++;

        fail[i] = j;
    }
    return fail;
}
void test()
{
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
