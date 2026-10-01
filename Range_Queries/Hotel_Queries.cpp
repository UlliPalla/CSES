#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+2;
vector<ll> tree(4*MAX_N+2,0);
 
void build(ll v,ll tl ,ll tr, vector<ll> &copy)
{
    if(tl==tr)
    {
        tree[v]=copy[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        tree[v]=max(tree[2*v],tree[2*v+1]);
    }
}
 
void update(ll v, ll tl ,ll tr, ll idx,ll val)
{
    if(tl==tr)
    {
        tree[v]+=val;
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
        tree[v]=max(tree[2*v],tree[2*v+1]);
    }
}
 
ll find_min_idx(ll v,ll tl,ll tr,ll K)
{
    if(tl==tr)
    {
        return tl+1;
    }
 
    ll tm=(tl+tr)/2;
    if(K<=tree[2*v])
    {
        return find_min_idx(2*v,tl,tm,K);
    }
    else if(K<=tree[2*v+1])
    {
        return find_min_idx(2*v+1,tm+1,tr,K);
    }
    else
    {
        return 0;
    }
}
 
 
int main()
{   
 
    //ifstream cin("input.txt");
    int N,Q;
    cin>>N>>Q;
    vector<ll> copy(N);
    for(int i=0;i<N;i++)
    {
        cin>>copy[i];
    }
    build(1,0,N-1,copy);
    for(int i=0;i<Q;i++)
    {
        ll x;
        cin>>x;
        if(tree[1]<x)
        {
            cout<<0<<" ";
            continue;
        }
        ll idx=find_min_idx(1,0,N-1,x);
        cout<<idx<<" ";
       
        update(1,0,N-1,idx-1,-x);
    }
}