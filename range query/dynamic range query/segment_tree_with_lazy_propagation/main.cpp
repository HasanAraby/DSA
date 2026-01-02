// problem b
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
//  segment tree can update only one element in o(logn) but with lazy propagation can update range or element in o(logn)

const int N = 2e5 + 10, mod = 1e9 + 7;
ll tree[N * 4], lazy[N * 4], a[N];
int n, q, l, r, val;

ll merge(ll a, ll b)
{
    return min(a, b);
}

// o(n)
void build(int node, int l, int r)
{
    lazy[node] = 0;
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int md = (l + r) >> 1;

    build(node * 2, l, md);
    build(node * 2 + 1, md + 1, r);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void propagate(int node, int l, int r)
{
    if (!lazy[node])
        return;

    // depend on the operation
    tree[node] += lazy[node];

    if (l != r)
    {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

// o(logn)
void update(int node, int l, int r, int s, int e, int val)
{
    propagate(node, l, r);

    if (l > e or r < s)
        return;

    if (l >= s and r <= e)
    {
        // depend on the operation
        lazy[node] += val;
        propagate(node, l, r);
        return;
    }

    int md = (l + r) >> 1;

    update(node * 2, l, md, s, e, val);
    update(node * 2 + 1, md + 1, r, s, e, val);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

// o(logn)
ll query(int node, int l, int r, int s, int e)
{
    propagate(node, l, r);
    if (l > e or r < s)
        return 1e13; // dummy
    if (l >= s and r <= e)
        return tree[node];

    int md = (l + r) >> 1;

    return merge(query(node * 2, l, md, s, e),
                 query(node * 2 + 1, md + 1, r, s, e));
}

void test()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n - 1);
    cin >> q;

    string s, in;
    cin.ignore();
    for (int j = 0; j < q; ++j)
    {

        vector<string> v;
        getline(cin, s);
        in = "";
        for (auto i : s)
        {
            if (i != ' ')
                in += i;
            else
            {
                v.push_back(in);
                in = "";
            }
        }
        v.push_back(in);

        l = stoi(v[0]);
        r = stoi(v[1]);
        if (sz(v) == 3)
            val = stoi(v[2]);

        int r1 = -1, l1 = -1;
        if (r < l)
            r1 = r, r = n - 1, l1 = 0;

        if (sz(v) == 3)
        {
            update(1, 0, n - 1, l, r, val);

            if (l1 == 0)
                update(1, 0, n - 1, l1, r1, val);
        }
        else
        {
            ll ans = query(1, 0, n - 1, l, r);
            if (l1 == 0)
                ans = merge(ans, query(1, 0, n - 1, l1, r1));

            cout << ans << en;
        }
    }
}

int main()
{
    tasree int t = 1;
    // cin >> t;
    while (t--)
    {
        test();
    }
    return 0;
}
