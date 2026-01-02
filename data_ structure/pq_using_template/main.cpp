#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 2e5+5;
const ll mod = 1e9+7;
int n, m;

template <class T>class MinHeap{

private:
    vector<T>data;

    int leftIndex(int parent){
        return parent * 2 + 1;
    }
    int rightIndex(int parent){
        return parent * 2 + 2;
    }
    int parentIndex(int child){
        return (child - 1) / 2;
    }

public:

    void push(T x){
        int index = (int)data.size();
        data.push_back(x);
        while(index > 0){
            if(data[index] < data[parentIndex(index)]){
                swap(data[index], data[parentIndex(index)]);
                index = parentIndex(index);
            }
            else
                break;
        }
    }
    void pop(){
        int index = 0;
        swap(data.front(), data.back());
        data.pop_back();

        while(rightIndex(index) < size()){
            if(data[index] <= data[leftIndex(index)] && data[index] <= data[rightIndex(index)])
                    return;
            if(data[rightIndex(index)] < data[leftIndex(index)]){
                swap(data[index], data[rightIndex(index)]);
                index = rightIndex(index);
            }
            else{
                swap(data[index], data[leftIndex(index)]);
                index = leftIndex(index);
            }
        }
        if(leftIndex(index) < size()){
            if(data[leftIndex(index)] < data[index])
                swap(data[index] , data[leftIndex(index)]);
        }
    }

    T top() const{
        return data.front();
    }
    int size() const{
        return (int)data.size();
    }
    bool empty() const{
        return data.empty();
    }
};

template <class T>struct cmp{
    bool operator()(T a, T b){
        return a>b;
    }
};

int main(){
    FIO

    MinHeap<vector<int>> pq;

//   priority_queue<int, vector<int>, cmp<int>>pq;

    pq.push(vector<int>{1,2});
    pq.push(vector<int>{1,2,3});
    pq.push(vector<int>{1,2,3,4,5});
    pq.push(vector<int>{1});
    pq.push(vector<int>{1,2,3,4});


    while(pq.size()){
        for(int z: pq.top()){
            cout<<z<<" ";
        }
        cout<<'\n';
        pq.pop();
    }

}
