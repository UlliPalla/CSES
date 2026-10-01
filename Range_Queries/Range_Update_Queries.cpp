#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+1;
vector<ll> tree(4*MAX_N+2,0);
 
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
        return query(2*v,tl,tm,l,min(tm,r)) + query(2*v+1,tm+1,tr,max(l,tm+1),r);
    }
}
 
void update(ll v,ll tl,ll tr,ll idx,ll val)
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
        tree[v]=tree[2*v]+tree[2*v+1];
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
    for(int i=0;i<Q;i++)
    {
        int s;
        cin>>s;
        if(s==1)
        {
            int c,b,x;
            cin>>c>>b>>x;
            c-=1;
            b-=1;
            update(1,0,N,c,x);
            update(1,0,N,b+1,-x);
        }
        else
        {
            int c;
            cin>>c;
            c-=1;
            cout<<a[c]+query(1,0,N,0,c)<<"\n";
        }
    }
}