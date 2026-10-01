#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<vector<ll>> grafo(N);
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
 
    }
    ll INF=1e12;
    vector<ll> parent(N,-1);
    vector<ll> num_f(N);
    vector<ll> sub(N,0);
    vector<bool> visto(N,false);
    vector<ll> dist(N,INF);
    vector<ll> sum_dist(N);
    stack<ll> st;
    st.push(0);
    ll root=0;
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
    queue<ll> que;
    for(int i=0;i<N;i++)
    {
        if(num_f[i]==0)
        {
            que.push(i);
        }
    }
    while(!que.empty())
    {
        ll node=que.front();
        que.pop();
        ll p=parent[node];
        if(p!=-1)
        {
            num_f[p]-=1;
            sub[p]+=(1+sub[node]);
            if(num_f[p]==0)
            {
                que.push(p);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        //cout<<sub[i];
    }
    queue<array<ll,2>> q;
    dist[root]=0;
    q.push({root,0});
    while(!q.empty())
    {
        ll node=q.front()[0];
        ll d=q.front()[1];
        q.pop();
        if(d>dist[node])
        {
            continue;
        }
        else
        {
            for(auto v:grafo[node])
            {
                ll tot=d+1;
                if(tot<dist[v])
                {
                    dist[v]=tot;
                    q.push({v,tot});
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        sum_dist[root]+=dist[i];
    }
    st.push(root);
    visto.assign(N,false);
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
                if(v!=parent[node])
                {   
                    if(!visto[v])
                    {
                        sum_dist[v]=sum_dist[node]+N-2*sub[v]-2;
                        st.push(v);
                    }
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<sum_dist[i]<<" ";
    }
 
 
 
 
 
}