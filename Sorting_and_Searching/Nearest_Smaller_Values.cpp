#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    //ifstream cin("input.txt");
    ll N;
    cin>>N;
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
 
 
    stack<ll> st;
    for(int i=0;i<N;i++)
    {
        while(!st.empty() and a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            cout<<0<<" ";
        }
        else
        {
            cout<<st.top()+1<<" ";
        }
        st.push(i);
        
    }
}