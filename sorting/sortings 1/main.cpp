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

const int N=1e5 + 100,mod=1e9+7;

//o(n*n)
void bubbleSort(vector<int>& arr){
for(int i=0; i<arr.size(); i++)
for(int j=0; j<arr.size()-1; j++)
     	if(arr[j]>arr[j+1])
       	swap(arr[j],arr[j+1]);
}


//o(n*n)
void selectionSort(vector<int>& arr){
  	for(int i=0; i<arr.size(); i++)
    	for(int j=i+1; j<arr.size(); j++)
      	if(arr[i]>arr[j])
        	swap(arr[i],arr[j]);
}

//o(n*n)
void insertionSort(vector<int>& arr){
  	for(int i=1; i<arr.size(); i++){
    	int cur=arr[i], j=i-1;
    	while(j>=0 && arr[j]>cur){
        	arr[j+1]=arr[j];
        	j--;
    	}
arr[j+1]=cur;
}
}

//o(n + d) d: domain or max element
void countSort(vector<int>& arr){
  	int mx=*max_element(arr.begin(), arr.end());
  	vector<int>freq(mx+1,0);
  	for(int x : arr) freq[x]++;

  	int i=0;
  	for(int val=0; val<=mx; val++)
    	while(freq[val]--)
      	arr[i++]=val;
}

// to shift number while processing negatives o(n + d)
void countSort(vector<int>& arr){
  	int shift=0;
  	int mn=*min_element(arr.begin(), arr.end());
  	if(mn<0) shift=-mn;
  	for(int &x : arr) x+=shift;

  	int mx=*max_element(arr.begin(), arr.end());
  	vector<int>freq(mx+1,0);
  	for(int x : arr) freq[x]++;

  	int i=0;
  	for(int val=0; val<=mx; val++)
   		while(freq[val]--)
      		arr[i++]=val-shift;
}

//for strings and floats you can use freq map o(nlogn)
void countSort(vector<string>& arr){
  	map<string,int>freq;
  	for(string& s : arr) freq[s]++;

  	int i=0;
  	for(auto& p : freq)
    	while(p.second--)
      		arr[i++]=p.first;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// radix use countsort on digits 0 : 9
void countSort(vector<int>&arr, int place){
  	vector<int> freq[10];
  	for(auto val : arr){
    		int digit=(val/place) %10;
    		freq[digit].push_back(val);
  	}
  	int i=0;
  	for(int i=0; i<10; i++)
    		for(auto val : freq[i])
      		arr[i++]=val;
}

//o(n * m) number of elements * length of max element
void radixSort(vector<int>& arr){
  	int mx=*max_element(arr.begin(), arr.end());
  	for(ll place=1; mx/place>0; place*=10)
    		countSort(arr,place);
}



void test()
{

}
int main()
{
tasree
int t=1;
cin>>t;
while(t--)
{
test();
}
return 0;
}
