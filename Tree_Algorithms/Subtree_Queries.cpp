#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+4;
vector<ll> t(4*MAX_N);
 
void build(ll v,ll tl,ll tr,vector<ll> &copy)
{
    if(tl==tr)
    {
        t[v]=copy[tr];
        return;
    }
    else
    {   
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        t[v]=t[2*v]+t[2*v+1];
    }
 
}
 
 
 
ll query(ll v,ll tl,ll tr,ll l,ll r)
{
    if(l>r)
    {
        return 0;
    }
    if(tl==l and tr==r)
    {
        return t[v];
    }
    else
    {   
        ll tm=(tr+tl)/2;
        return query(2*v,tl,tm,l,min(r,tm))+
               query(2*v+1,tm+1,tr,max(tm+1,l),r);
    }
}
 
void update(ll v,ll tl,ll tr,ll idx,ll val)
{
    if(tr==tl)
    {
        t[v]=val;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(idx>tm)
        {
            update(2*v+1,tm+1,tr,idx,val);
        }
        else
        {
            update(2*v,tl,tm,idx,val);
        }
        t[v]=t[2*v]+t[2*v+1];
    }
}
 
int main()
{
    int N,Q;
    cin>>N>>Q;
    ll root=0;
    vector<vector<ll>> grafo(N);
    vector<ll> val(N);
    vector<ll> in(N);
    vector<ll> out(N);
    vector<ll> parent(N);
    vector<ll> flat(N);
    parent[root]=-1;
    vector<bool> visto(N,false);
    for(int i=0;i<N;i++)
    {
        cin>>val[i];
    }
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    stack<ll> st;
    ll t=0;
    st.push(root);
    while(!st.empty())
    {
        ll node=st.top();
        
        if(!visto[node])
        {   
            visto[node]=true;
            in[node]=(t);
            t+=1;
            flat[in[node]]=val[node];
            for(auto v:grafo[node])
            {
                if(!visto[v])
                {   
                    parent[v]=node;
                    st.push(v);
                }
            }
        }
        else
        {
            st.pop();
            out[node]=t-1;
        }
    }
    build(1,0,N-1,flat);
    for(int i=0;i<Q;i++)
    {
        int s;
        cin>>s;
        if(s==1)
        {
            int a,b;
            cin>>a>>b;
            a-=1;
            update(1,0,N-1,in[a],b);
        }
        else
        {
            int a;
            cin>>a;
            a-=1;
            cout<<query(1,0,N-1,in[a],out[a])<<" \n";
        }
    }
 
 
    
 
 
}