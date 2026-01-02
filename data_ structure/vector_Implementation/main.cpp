#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define tasree ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);


class Vector{
private:
      int m_size;
     int *m_data;
     int m_cap;
    void expand()
    {
        int *new_data= new int[2*m_size];
        m_cap*=2;
        memcpy(new_data ,m_data ,m_size * sizeof(int));
        delete[] m_data;
        m_data=new_data;
    }

    void shrink()
    {
         int *new_data= new int[m_cap/2];
        memcpy(new_data ,m_data ,m_size * sizeof(int));
         delete[] m_data;
         m_data=new_data;
         m_cap/=2;
    }

public:

    Vector(){
     m_size=0;
      m_data=new int[4];
     m_cap=4;
    };



    void pushBack(int x)
    {

        if(m_size==m_cap)
            expand();
            m_data[m_size++]=x;
    }

    void popBack()
    {
        m_size--;
        if(2*m_size < m_cap)
            shrink();
    }

    int &operator[](int x)
    {
        return m_data[x];
    }
    int size()
    {
        return m_size;
    }

};






int main()
{
    Vector v;
    v.pushBack(10);
    v.pushBack(7);
    v.pushBack(8);
    v.popBack();
    v.pushBack(4);
v[0]=4;
    for(int i=0;i<v.size();++i)
        cout<<v[i]<<" ";
    return 0;
}
