#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    //ifstream cin("input.txt");
    ll N,M;
    cin>>N>>M;
    vector<vector<ll>> grafo1(N);
    vector<vector<ll>> grafo2(N);
    for(int i=0;i<M;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        grafo1[a].push_back(b);
        grafo2[b].push_back(a);
    }
    //cout<<"sasa";
    vector<bool> visto(N);
    stack<ll> st;
    st.push(0);
    while(!st.empty())
    {
        ll node=st.top();
        st.pop();
        if(!visto[node])
        {   
            visto[node]=true;
            for(auto v:grafo1[node])
            {
                if(!visto[v])
                {
                    st.push(v);
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {        
        if(!visto[i])
        {
            cout<<"NO\n";
            cout<<1<<" "<<i+1;
            return 0;
        }
    }
    visto.assign(N,false);
    st.push(0);
    while(!st.empty())
    {
        ll node=st.top();
        st.pop();
        if(!visto[node])
        {   
            visto[node]=true;
            for(auto v:grafo2[node])
            {
                if(!visto[v])
                {
                    st.push(v);
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {        
        if(!visto[i])
        {
            cout<<"NO\n";
            cout<<i+1<<" "<<1;
            return 0;
        }
    }
    cout<<"YES";
}