#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+1;
vector<ll> tree(4*MAX_N+2,1);
 
void build(ll v,ll tl ,ll tr)
{   
    if(tl==tr)
    {
        tree[v]=1;
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
}
 
void update(ll v, ll tl ,ll tr, ll idx ,ll val)//assign update
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
        tree[v]=tree[2*v]+tree[2*v+1];
    }
}
 
ll poplist(ll v, ll tl,ll tr,ll idx)
{
    if(tl==tr)
    {
        return tl;
    }
    else
    {
        ll tm=(tl+tr)/2;
        if(idx>tree[2*v])
        {
            return poplist(2*v+1,tm+1,tr,idx-tree[2*v]);
        }
        else
        {
            return poplist(2*v,tl,tm,idx);
        }
    }
}
 
int main()
{   
    //ifstream cin("input.txt");
    int N;
    cin>>N;
    build(1,0,N-1);
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<N;i++)
    {
        int x;
        cin>>x;
        ll idx=poplist(1,0,N-1,x);
        update(1,0,N-1,idx,0);
        cout<<a[idx]<<" ";
    }
}