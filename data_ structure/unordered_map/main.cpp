//using template to make it accept any data type
#include <bits/stdc++.h>
#define ll long long
#define FIO ios_base::sync_with_stdio(false), cout.tie(nullptr); cin.tie(nullptr);
using namespace std;
const int N = 2e5+5;
const ll mod = 1e9+7;
int n, m;

template <class T, class U>struct Node{
    T key;
    U value;
    Node *next;
    Node(T key, U value, Node *next): key(key), value(value), next(next){}
};

template <class T, class U>class LinkedList{

private:
    Node<T, U> *head;

public:

    LinkedList(): head(NULL){}

    bool insert(T key, U value){
        if(count(key) == 0){
            head = new Node<T, U>(key, value, head);
            return 1;
        }
        return 0;
    }
    bool count(T key){
        Node<T, U> *cur = head;
        while(cur){
            if(cur->key == key)
                return 1;
            cur = cur->next;
        }
        return 0;
    }
    int erase(T key){
        if(head == NULL)
            return 0;

        if(head->key == key){
            Node<T, U> *temp = head;
            head = head->next;
            delete temp;
            return 1;
        }

        Node<T, U> *cur = head;
        while(cur->next){
            if(cur->next->key == key){
                Node<T, U> *temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                return 1;
            }
            cur = cur->next;
        }
        return 0;
    }

    U& find_value(T key){
        Node<T, U> *cur = head;
        while(cur){
            if(cur->key == key)
                return cur->value;
            cur = cur->next;
        }
        assert(false);
    }

};

template <class T, class U>class HashTable{

private:
    vector<LinkedList<T, U>>buckets;
    int m_size, capacity;

    int hash(int key){
        return (key%capacity + capacity)%capacity;
    }

public:

    HashTable(int capacity): buckets(capacity), m_size(0), capacity(capacity){}

    void insert(T key, U value){
        int hashed = hash(key);
        m_size += buckets[hashed].insert(key, value);
    }
    bool count(T key){
        int hashed = hash(key);
        return buckets[hashed].count(key);
    }
    void erase(T key){
        int hashed = hash(key);
        m_size -= buckets[hashed].erase(key);
    }
    int size() const{
        return m_size;
    }
    bool empty(){
        return m_size == 0;
    }

    U& operator[](T key){
        int hashed = hash(key);
        if(buckets[hashed].count(key) == 0){
            U* temp = new U();
            buckets[hashed].insert(key, *temp);
        }
        return buckets[hashed].find_value(key);
    }
};

int main(){
//    FIO






}


