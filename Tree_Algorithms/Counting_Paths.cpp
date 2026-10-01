#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
ll LCA(ll v, ll u,vector<ll> &depth,vector<vector<ll>> &up)
{   
    ll LOG=20;
    if(depth[u]<depth[v])
    {
        swap(u,v);
    }
    ll d=depth[u]-depth[v];
    for(int j=0;j<LOG;j++)
    {
        if((d>>j)&1)
        {
            u=up[u][j];
        }
    }   
    if(u==v)
    {
        return u;
    }
    for(int j=LOG-1;j>=0;j--)
    {
        if(up[u][j]!=up[v][j])
        {   
            if(up[u][j]!=-1 and up[v][j]!=-1)
            {
                u=up[u][j];
                v=up[v][j];
            }
        }
    }
    return up[u][0];
}
 
 
 
 
int main()
{
    int N,M;
    ll root=0;
    ll LOG=20;
    cin>>N>>M;
    vector<ll> num_f(N,0);
    vector<vector<ll>> grafo(N);
    vector<ll> parent(N);
    vector<ll> visto(N,false);
    vector<vector<ll>> up(N,vector<ll> (LOG+1));
    vector<ll> depth(N,LONG_LONG_MAX);
    vector<ll> val(N,0);
    vector<ll> visit_order;
    vector<ll> sol(N,0);
    queue<ll> q;
    stack<ll> st;
    queue<ll> que;
    visit_order.push_back(root);
    depth[root]=0;
    parent[root]=-1;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    
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
    
    que.push(root);
    while(!que.empty())
    {
        ll node=que.front();
        que.pop();
        for(auto v:grafo[node])
        {
            if(depth[node]+1<depth[v])
            {
                depth[v]=depth[node]+1;
                que.push(v);
            }
        }
    }
    for(int i=0;i<N;i++)
    {   
        up[i][0]=parent[i];
        //cout<<num_f[i]<<" ";
    }
    for(int step=0;step<LOG;step++)
    {
        for(int node=0;node<N;node++)
        {
            if(up[node][step]!=-1)
            {
                up[node][step+1]=up[up[node][step]][step];
            }
            else
            {
                up[node][step+1]=-1;
            }
        }
    }
    for(int i=0;i<M;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        ll lca=LCA(a,b,depth,up);
        val[a]+=1;
        val[b]+=1;
        val[lca]-=1;
        if(parent[lca]!=-1)
        {
            val[parent[lca]]-=1;
        }
    }
   
    
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
            val[p]+=val[node];
            if(num_f[p]==0)
            {   
                q.push(p);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<val[i]<<" ";
    }
 
 
    
 
    
 
    
 
}