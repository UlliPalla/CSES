#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+2;
vector<ll> t(8*MAX_N);
 
void build(ll v,ll tl, ll tr,vector<ll> &copy)
{
    if(tl==tr)
    {
        t[v]=copy[tl];
        return;        
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        t[v]=t[2*v]+t[2*v+1];
    }
    return;
}
 
void update(ll v,ll tl,ll tr,ll idx,ll val)
{
    if(tl==tr)
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
        ll tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(r,tm))+query(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
 
}
 
 
 
int main()
{
    int N,Q;
    cin>>N>>Q;
    ll root=0;
    vector<ll> val(N);
    vector<vector<ll>> grafo(N);
    vector<ll> parent(N);
    parent[0]=-1;
    vector<ll> in(N);
    vector<ll> out(N);
    vector<ll> flat(2*N+1);
    for(int i=0;i<N;i++)
    {
        cin>>val[i];
    }
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
    ll time=1;
    st.push(root);
    while(!st.empty())
    {
        ll node=st.top();
        if(!visto[node])
        {   
            visto[node]=true;
            in[node]=time;
            flat[in[node]]=val[node];
            time+=1;
            for(auto v:grafo[node])
            {   
                if(v!=parent[node])
                {
                    parent[v]=node;
                    st.push(v);
                }
            }
        }
        else
        {
            out[node]=time;
            time+=1;
            flat[out[node]]=-val[node];
            st.pop();
        }
    }
    build(1,1,2*N,flat);
    for(int i=0;i<Q;i++)
    {
        int s;
        cin>>s;
        if(s==1)
        {
            int a,b;
            cin>>a>>b;
            a-=1;
            update(1,1,2*N,in[a],b);
            update(1,1,2*N,out[a],-b);
        }
        else
        {
            int a;
            cin>>a;
            a-=1;
            cout<<query(1,1,2*N,1,in[a])<<" \n";
        }
    }
 
}