#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 2e5+5;
const ll mod = 1e9+7;
int n, m;

struct Node{
    int data;
    Node *next;
    Node(int data, Node *next): data(data), next(next){}
};

class LinkedList{

private:
    Node *head;

public:

    LinkedList(): head(NULL){}

    bool insert(int data){
        if(count(data) == 0){
            head = new Node(data, head);
            return 1;
        }
        return 0;
    }
    bool count(int data){
        Node *cur = head;
        while(cur){
            if(cur->data == data)
                return 1;
            cur = cur->next;
        }
        return 0;
    }
    int erase(int data){
        if(head == NULL)
            return 0;

        if(head->data == data){
            Node *temp = head;
            head = head->next;
            delete temp;
            return 1;
        }

        Node *cur = head;
        while(cur->next){
            if(cur->next->data == data){
                Node *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return 1;
            }
            cur = cur->next;
        }
        return 0;
    }

};

//Unordered set
class HashTable{

private:
    vector<LinkedList>buckets;
    int m_size, capacity;

    int hash(int data){
        return (data%capacity + capacity)%capacity;
    }

public:

    HashTable(int capacity): buckets(capacity), m_size(0), capacity(capacity){}

    void insert(int data){
        int hashed = hash(data);
        m_size += buckets[hashed].insert(data);
    }
    bool count(int data){
        int hashed = hash(data);
        return buckets[hashed].count(data);
    }
    void erase(int data){
        int hashed = hash(data);
        m_size -= buckets[hashed].erase(data);
    }
    int size() const{
        return m_size;
    }
    bool empty(){
        return m_size == 0;
    }

};

int main(){
//    FIO

    HashTable st(1e5);

    int q;
    cin>>q;
    while(q--){
        int n, x;
        cin>>n>>x;

        if(n == 1){
            st.insert(x);
        }
        else if(n == 2){
            cout<<(st.count(x)? "Exists" : "Not exists")<<'\n';
        }
        else{
            st.erase(x);
        }
    }

}
