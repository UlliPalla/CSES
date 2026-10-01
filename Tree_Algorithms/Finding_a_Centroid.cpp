#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    ll root=0;
    vector<vector<ll>> grafo(N);
    vector<ll> parent(N);
    vector<ll> num_f(N,0);
    vector<ll> sub(N,1);
    parent[root]=-1;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    vector<ll> visto(N,false);
    stack<ll> st;
    st.push(root);
    while(!st.empty())
    {
        ll node=st.top();
        st.pop();
        if(visto[node])
        {
            continue;
        }
        else
        {
            visto[node]=true;
            for(auto v:grafo[node])
            {
                if(!visto[v])
                {
                    parent[v]=node;
                    num_f[node]+=1;
                    st.push(v);
                }
            }
        }
    }
    queue <ll> q;
    for(int i=0;i<N;i++)
    {
        if(num_f[i]==0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        ll p=parent[node];
        if(p!=-1)
        {
            num_f[p]-=1;
            sub[p]+=sub[node];
            if(num_f[p]==0)
            {
                q.push(p);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        //cout<<sub[i]<<" ";
    }
    ll cur_=root;
    while(true)
    {   
        ll heavy=-2;
        for(auto v:grafo[cur_])
        {
            if(v!=parent[cur_] and sub[v]>N/2)
            {
                heavy=v;
                break;
            }
        }
        if(heavy==-2)
        {
            cout<<cur_+1<<" ";
            break;
        }
        cur_=heavy;
        
    }
 
 
}