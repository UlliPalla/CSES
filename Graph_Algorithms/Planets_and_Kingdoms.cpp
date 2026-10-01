#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,M;
    cin>>N>>M;
    vector<vector<ll>> grafo(N);
    vector<vector<ll>> antigrafo(N);
    for(int i=0;i<M;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        grafo[a].push_back(b);
        antigrafo[b].push_back(a);
    }
    vector<ll> post;
    vector<bool> visto(N,false);
    for(int i=0;i<N;i++)
    {
        stack<array<ll,2>> st;
        st.push({i,0});
        while(!st.empty())
        {
            auto [node,s]=st.top();
            st.pop();
            if(s==1)
            {
                post.push_back(node);
                continue;
            }
            if(!visto[node])
            {
                visto[node]=true;
                st.push({node,1});
                for(auto v:grafo[node])
                {
                    if(!visto[v])
                    {
                        st.push({v,0});
                    }
                }
            }
        }
    }
    reverse(post.begin(),post.end());
    visto.assign(N,false);
    vector<ll> sol(N);
    ll sol_=0;
    for(auto u:post)
    {
        if(visto[u])
        {
            continue;
        }
        sol_+=1;
        stack<ll> st1;
        st1.push(u);
        while(!st1.empty())
        {
            ll node=st1.top();
            st1.pop();
            if(!visto[node])
            {
                visto[node]=true;
                sol[node]=sol_;
                for(auto v:antigrafo[node])
                {
                    if(!visto[v])
                    {
                        st1.push(v);
                    }
                }
            }
        }
    }
    cout<<sol_<<"\n";
    for(int i=0;i<N;i++)
    {
        cout<<sol[i]<<" ";
    }
 
}