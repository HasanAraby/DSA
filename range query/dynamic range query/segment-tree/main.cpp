#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
// diffirence between sparse table and segment tree is segement tree can be updated
//  segment tree can update only one element in o(logn) but with lazy propagation can update range or element in o(logn)
// not on trees or graphs
// sum or xor min max gcd
const int N = 2e5 + 10, mod = 1e9 + 7;
int tree[N * 4], a[N];
int merge(int lft, int rt)
{
    return lft + rt;
}
// build o(n)
void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = a[l];
        return;
    }

    int md = (l + r) >> 1;
    // divide
    build(node * 2, l, md);
    build(node * 2 + 1, md + 1, r);
    // conquer
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}
// update o(logn)
void update(int node, int l, int r, int idx, int val)
{
    if (l == r)
    {
        tree[node] = val;
        return;
    }

    int md = (l + r) >> 1;
    if (idx <= md)
        update(node * 2, l, md, idx, val);
    else
        update(node * 2 + 1, md + 1, r, idx, val);
    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

// query o(logn)
ll query(int node, int l, int r, int s, int e)
{
    if (l > e or r < s)
        return 0;
    // dummy can be changed due to the operation
    // mx->-1 mn->2e9 sum->0 mul->1
    if (l >= s and r <= e)
        return tree[node];

    int md = (l + r) >> 1;
    return merge(query(node * 2, l, md, s, e), query(node * 2 + 1, md + 1, r, s, e));
}
int n;
int tst = 0;
void test()
{
    // build,update,query always node=1   ,l,r,s,e,idx,a[i]  all are (zero based or one based)
    cout << "Case " << ++tst << ':' << en;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    build(1, 0, n - 1);
    string s;
    while (cin >> s and s != "END")
    {
        if (s == "S")
        {
            int x, r;
            cin >> x >> r;
            update(1, 0, n - 1, x - 1, r);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << query(1, 0, n - 1, x - 1, y - 1) << en;
        }
    }
}

int main()
{
    tasree int t = 1;
    // cin>>t;
    while (cin >> n and n)
    {
        if (t > 1)
            cout << en;
        test();
        t++;
    }
    return 0;
}
