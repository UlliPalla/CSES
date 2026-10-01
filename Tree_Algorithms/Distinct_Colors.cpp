#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> C(N);
    for(int i=0;i<N;i++)
    {
        cin>>C[i];
    }
    vector<vector<ll>> grafo(N);
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a;
        cin>>b;
        a-=1;
        b-=1;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    vector<ll> parent(N);
    ll root=0;
    parent[root]=-1;
    vector<bool> visto(N,false);
    vector<ll> order;
    stack<ll> st;
    vector<ll> num_f(N,0);
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
            order.push_back(node);
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
    vector<set<ll>> dist(N);
    queue<ll> q;
    vector<ll> sol(N,0);
    for(int i=0;i<N;i++)
    {
        if(num_f[i]==0)
        {
            q.push(i);
        }
        dist[i].insert(C[i]);
    }
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        ll p=parent[node];
        sol[node]=dist[node].size();
        if(p!=-1)
        {
            num_f[p]-=1;
            if(dist[node].size()>dist[p].size())
            {
                dist[node].swap(dist[p]);
            }
            for(auto d:dist[node])
            {
                dist[p].insert(d);
            }
            dist[node].clear();
            if(num_f[p]==0)
            {
                q.push(p);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<sol[i]<<" ";
    }
    
}