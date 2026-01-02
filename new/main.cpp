#pragma GCC optimze "trapv"
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define all(x) x.begin(),x.end()
#define sz(x) int(x.size())

const int N=1e4 + 10, M = 1e6 + 5, mod=1e9+7;
int tree[N * 4], a[N], lazy[N * 4], notP[M];
int n, q, l, r, val, tp;

int merge(int a, int b)
{
    return a + b;
}

void build(int node, int l, int r)
{
    lazy[node] = 0;
    if(l == r)
    {
        tree[node] = (notP[a[l]] ^ 1);
        return;
    }

    int md = (l + r) >> 1;

    build(node * 2, l, md);
    build(node * 2 + 1, md + 1, r);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

void propagate(int node, int l, int r)
{
    if(!lazy[node]) return;
    if(notP[lazy[node]])
       tree[node] = 0;
    else tree[node] = r - l + 1;

    if(l != r)
    {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }

     lazy[node] = 0;
}


void update(int node, int l, int r, int s, int e, int val)
{
    propagate(node, l, r);

    if(l > e or r < s) return;

    if(l >= s and r <= e)
    {
        lazy[node] = val;
        propagate(node, l, r);
        return;
    }

    int md = (l + r) >> 1;

    update(node * 2, l, md, s, e, val);
    update(node * 2 + 1, md + 1, r, s, e, val);

    tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
}

int query(int node, int l, int r, int s, int e)
{
    propagate(node, l, r);
    if(l > e or r < s) return 0; //dummy
    if(l >= s and r <= e) return tree[node];

    int md = (l + r) >> 1;

    return merge(query(node * 2, l, md, s, e),
                 query(node * 2 + 1, md + 1, r, s, e));
}

void test()
{
    cout << "h" << en;
cin >> n >> q;
for(int i = 1; i <= n; ++i) cin >> a[i];
build(1, 1, n);
while(q--)
{
    cin >> tp >> l >> r;
    if(!tp)
    {
        cin >> val;
        update(1, 1, n, l, r, val);
    }
    else
    cout << query(1, 1, n, l, r) << en;
}
}


int main()
{
tasree
//cout << "h" << en;
for(int i = 2; i <= 1e6; ++i)
    for(int j = i + i; j <= 1e6; j += i)
        notP[j] = 1;

int t = 1;
cin >> t;
for(int i = 1; i <= t; ++i)
{
cout << "Case " << i << ":\n";
test();
}
return 0;
}
