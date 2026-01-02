#include <bits/stdc++.h>

using namespace std;
#define tasree ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long

struct Node{
int value;
Node *next;
};

class linkedList
{
private:
    Node *tail, *head;
public:


    linkedList()
    {
       head=tail=NULL;

    }

   void addTail(int x)
    {
         Node *newNode= new Node();
        newNode->value=x;
        newNode->next=NULL;


        if(head==NULL)
            head=tail=newNode;
        else
        {
             tail->next = newNode;
        tail=newNode;
        }
    }

   void addHead(int x)
    {
        Node *newNode= new Node();

        newNode->next=NULL;
        newNode->value=x;

        if(head==NULL)
            head=tail=newNode;
        else
        {
            newNode->next=head;
            head=newNode;

        }


    }

    void print()
    {
        Node *cur=head;

        while(cur!=NULL)
        {
            cout<<cur->value<<" ";
            cur=cur->next;
        }
    }
};

int main()
{
linkedList v;
v.addTail(10);
v.addTail(6);
v.addHead(4);
v.addTail(7);
v.addHead(8);
v.addTail(11);

v.print();
    return 0;
}
