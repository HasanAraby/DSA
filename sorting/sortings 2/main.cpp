#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long


void merge (int l, int mid, int r, vector<int>&arr)
{
    vector<int>L;
    vector<int>R;

    for(int i=l;i<=mid;++i)
        L.push_back(arr[i]);

    for(int i=mid+1;i<=r;++i)
        R.push_back(arr[i]);

    R.push_back(INT_MAX);
    L.push_back(INT_MAX);

    int lin=0,rin=0;

    for(int i=l;i<=r;++i)
    {
        if(L[lin]<=R[rin])
            arr[i]=L[lin++];
        else
            arr[i]=R[rin++];
    }

}

//o(nlogn)
void mergesort(int l,int r,vector<int>&arr)
{
    if(l>=r) return;

    int mid=(r+l)/2;

    mergesort(l,mid,arr);
    mergesort(mid+1,r,arr);
    merge(l,mid,r,arr);


}
///////////////////////////////////////////////////////////////////////////////////////////////////////
pair<int,int> partition(int l,int r,vector<int>&arr)
{
    int m1=l-1, m2=l;

    for(int i=l+1;i<=r;++i)
    {
        if(arr[i]<arr[m2])
        {
            swap(arr[i],arr[++m1]);
            swap(arr[i],arr[++m2]);

        }

        else if(arr[i]==arr[m2])
        {
            swap(arr[i],arr[++m2]);
        }

    }

    return {m1+1,m2};
}

//best case o(n)  average case o(nlogn)  worst case o(n*n)
void quicksort(int l, int r, vector<int>&arr)
{
if(l>=r)
return;

    pair<int ,int>m1m2=partition(l, r, arr);

  quicksort(l, m1m2.first-1, arr);


  quicksort(m1m2.second+1, r, arr);


}
struct comp{
bool operator()(pair<int,int>x,pair<int,int>y)
{
    if(x.first==y.first)
        return x.second<y.second;

    return x.first<y.first;
}
};


int main(){

int t;cin>>t;
while(t--)
{

set<pair<int,int>,comp>s;

s.insert({4, 7});
s.insert({4, 5});
s.insert({4, 3});
s.insert({4, 10});
s.insert({2, 5});
s.insert({10, 1});

for(auto i: s) cout << i.first << ' ' << i.second << endl;
//int n;cin>>n;
//vector<int>uns(n);
//vector<pair<int,int>>v;
//int x;
//for(int i=0;i<n;++i)
//{
//    cin>>x;uns[i]=x;
//    s.insert({x,i});
//
//}
//int count=0;
//for(auto z:s)
//v.push_back({z.first,z.second});
//int l=0;
//for(int i=0;i<n;++i)
//{
//    if(v[i].second>i)
//    {
//        count+=(v[i].second-l);
//        v[(uns[i],i)].second=4;
//    }
//}
//
//cout<<count<<'\n';


}

  return 0;
}

