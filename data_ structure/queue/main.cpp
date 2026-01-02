#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 5e4+5;
const ll mod = 1e9+7;

struct Node{
    int value;
    Node *next;
    Node(int v): value(v), next(NULL){}
};

class Queue{
private:
    int m_size;
    Node *head, *tail;

public:

    Queue(): m_size(0), head(NULL), tail(NULL){}

    void push(int value){
        Node *newNode = new Node(value);
        m_size++;

        if(head == NULL){
            head = tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop(){
        if(!m_size)return;
        m_size--;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int& front(){
        return head->value;
    }
    int& back(){
        return tail->value;
    }
    int size() const{
        return m_size;
    }
    bool empty(){
        return m_size == 0;
    }

};

int main(){
    FIO

    Queue q;
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;

        if(n == 1){
            cin>>x;
            q.push(x);
        }
        else if(n == 2){
            if(q.size())
                q.pop();
        }
        else{
            if(q.empty())
                cout<<"Empty!\n";
            else
                cout<<q.front()<<'\n';
        }

    }

}
