#pragma GCC optimze "trapv"
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define en '\n'
#define F first
#define S second
#define tasree ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define ld long double
const int N = 26 + 10, M = 55, MOD = 1e9 + 7, MX = INT_MAX;
// time complexity: o(nl)
// n: #words
// l: average length of each word
// the class represent a char contains => char next, char count and if this char was end of an word
struct Node
{
    bool is_word = false;
    int cnt = 0;
    Node *next[N]{};
    void insert(const string &s) // & better for time
    {
        Node *current = this;
        for (char c : s)
        {
            int i = c - 'a';
            if (current->next[i] == nullptr)
                current->next[i] = new Node;
            current = current->next[i];
            ++current->cnt;
        }
        current->is_word = true;
    }

    bool contains(const string &s)
    {
        Node *current = this;
        for (char c : s)
        {
            int i = c - 'a';
            if (current->next[i] == nullptr)
                return false;
            current = current->next[i];
        }
        return current->is_word;
    }

    int count(string &s)
    {
        Node *current = this;
        for (char c : s)
        {
            int i = c - 'a';
            if (current->next[i] == nullptr)
                return 0;
            current = current->next[i];
        }
        return current->cnt;
    }

    // destructor to delete from down to up
    // to clear if there is a multiple testcase problem
    // take the same obj and destructor will free it auto after ending better than new obj every test case for memory
    ~Node()
    {
        for (int i = 0; i < N; ++i)
        {
            delete next[i];
            next[i] = nullptr;
        }
    }
};
void test()
{
    Node trie;
    char op;
    string s;
    while (true)
    {
        cin >> op;
        cin >> s;
        if (op == '+')
            trie.insert(s);
        else if (op == '?')
            cout << trie.contains(s);
        else
            cout << trie.count(s);
        cout << en;
    }
}
int main()
{
    // tasree
    int t = 1;
    // cin>>t;
    while (t--)
    {
        test();
    }
    return 0;
}
