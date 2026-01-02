#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 5e4+5;
const ll mod = 1e9+7;

struct Node{
    int value;
    Node *next;
    Node(int value, Node *next): value(value), next(next){}
};

class Stack{
private:
    Node *head;
    int m_size;

public:

    Stack(): m_size(0), head(NULL){}

    void push(int value){
        Node *newNode = new Node(value, NULL);
        m_size++;

        if(head == NULL){
            head = newNode;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
    }

    void pop(){
        m_size--;
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    int& top(){
        return head->value;
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

    Stack st;

    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n;

        if(n == 1){
            cin>>x;
            st.push(x);
        }
        else if(n == 2){
            if(st.size())
                st.pop();
        }
        else{
            if(st.empty())
                cout<<"Empty!\n";
            else
                cout<<st.top()<<'\n';
        }

    }
}
