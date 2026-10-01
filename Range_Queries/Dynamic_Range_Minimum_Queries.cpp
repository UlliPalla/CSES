#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+1;
vector<ll> tree(4*MAX_N);
 
 
 
void build(ll v, ll tl ,ll tr,vector<ll> &copy)
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
        tree[v]=min(tree[2*v],tree[2*v+1]);
    }
}
 
void update( ll v,ll tl, ll tr, ll idx ,ll val)
{
    if(tl==tr)
    {
        tree[v]=val;
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
        tree[v]=min(tree[2*v],tree[2*v+1]);
    }
}
 
ll query(ll v,ll tl, ll tr,ll l ,ll r)
{
    if(l>r)
    {
        return LONG_LONG_MAX;
    }
    else if(tl==l and tr==r)
    {
        return tree[v];
    }
    else
    {
        ll tm=(tl+tr)/2;
        return min(query(2*v,tl,tm,l,min(r,tm)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
    }
}
 
 
 
int main()
{   
    //ifstream cin("input.txt");
    int N,Q;
    cin>>N>>Q;
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    build(1,0,N-1,a);
    for(int i=0;i<Q;i++)
    {
        int s,c,d;
        cin>>s>>c>>d;
        c-=1;
        d-=1;
        if(s==1)
        {
            update(1,0,N-1,c,d+1);
        }
        else
        {
            cout<<query(1,0,N-1,c,d)<<"\n";
        }
    }
}