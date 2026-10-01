#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+1;
vector<ll> tree(4*MAX_N+4);
 
void build(ll v,ll tl,ll tr,vector<ll>&copy)
{
    if(tl==tr)
    {
        tree[v]=copy[tl];
        return;
    }
    else
    {
        ll tm=(tr+tl)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        tree[v]=tree[2*v]+tree[2*v+1];
        return;
    }
 
}
 
 
 
void update(ll v,ll tl,ll tr,ll idx,ll val)
{
    if(tl==tr)
    {
        tree[v]=val;
        return;
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
        tree[v]=tree[2*v]+tree[2*v+1];
        return;
    }
}
 
 
ll query(ll v,ll tl,ll tr,ll l ,ll r)
{
    if(l>r)
    {
        return 0;
    }
    else if(tl==l and tr==r)
    {
        return tree[v];
    }
    else
    {
        ll tm=(tl+tr)/2;
        return query(2*v,tl,tm,l,min(r,tm))+query(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
 
}
 
 
int main()
{
    //ifstream cin("input.txt");
    ll N,Q;
    cin>>N>>Q;
    vector<ll> copy(N);
    for(int i=0;i<N;i++)
    {
        cin>>copy[i];
    }
    build(1,0,N-1,copy);
    for(int i=0;i<Q;i++)
    {
        ll s,a,b;
        cin>>s>>a>>b;
        a-=1;
        b-=1;
        if(s==1)
        {
            update(1,0,N-1,a,b+1);
        }
        else
        {
            cout<<query(1,0,N-1,a,b)<<"\n";
        }
    }
    
}