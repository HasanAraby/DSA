#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 2e5+5;
const ll mod = 1e9+7;
int n, m;

class MinHeap{

private:
    vector<int>data;

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

    void push(int x){
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

    int top() const{
        return data.front();
    }
    int size() const{
        return (int)data.size();
    }
    bool empty() const{
        return data.empty();
    }
};

int main(){
//    FIO

    MinHeap pq;

    pq.push(5);
    pq.push(7);
    pq.push(1);
    pq.push(13);
    pq.push(2);
    pq.push(6);
    pq.push(546);
    pq.push(45);
    pq.push(25);
    pq.push(23);
    pq.push(17);
    pq.push(3);
    pq.push(99);
    pq.push(454646);


    while(pq.size()){
        cout<<pq.top()<<'\n';
        pq.pop();
    }

}
