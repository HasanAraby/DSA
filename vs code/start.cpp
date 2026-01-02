#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())

const ll N = 1e5 + 10, M = 55, MOD = 1e9 + 7, MX = 1e18;
string ar[5];

void test()
{
	string inp;
	int l = 1, r = 1e6, md;
	while(cin >> inp){
        md = l + (r - l) / 2;
		cout << md;
		fflush(stdout);
		if(inp[0] == '<')
		    l = md + 1;
		else r = md;
	}

	md = l + (r - 1) / 2;
	cout << md;
fflush(stdout);

}
int main()
{
	tasree;
	 int t = 1;
	  cin >> t;
	while (t--)
	{
		test();
	}
	return 0;
}