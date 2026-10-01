#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+1;
vector<int> tree(4*MAX_N+2,0);
 
void build(ll v, ll tl ,ll tr ,vector<int> &copy)
{
    if(tr==tl)
    {
        tree[v]=copy[tl];
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        tree[v]=tree[2*v]+tree[2*v+1];
    }
 
}
 
 
void update(ll v, ll tl ,ll tr,ll idx ,int val)//sum
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
 
int query(ll v ,ll tl ,ll tr,ll l ,ll r)
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
        return query(2*v,tl,tm,l,min(tm,r))+query(2*v+1,tm+1,tr,max(tm+1,l),r);
    }
}
 
struct Query
{
    char t;
    ll a,b;
};
 
int main()
{   
    //ifstream cin("input.txt");
    int N,Q;
    cin>>N>>Q;
    vector<ll> val;
    vector<ll> p(N+1);
    for(int i=1;i<=N;i++)
    {
        cin>>p[i];
        val.push_back(p[i]);
    }
    vector<Query> q(Q);
    for(int i=0;i<Q;i++)
    {
        cin>>q[i].t>>q[i].a>>q[i].b;
        val.push_back(q[i].b);
        if(q[i].t=='?')
        {
            val.push_back(q[i].a);
        }
    }
    sort(val.begin(),val.end());
    val.erase(unique(val.begin(),val.end()),val.end());
    ll M=val.size();
    tree.assign(4*M+5,0);
 
    for(int i=1;i<=N;i++)
    {
        ll idx=lower_bound(val.begin(),val.end(),p[i])-val.begin();
        update(1,0,M-1,idx,+1);
    }
 
    for(auto [t,a,b]:q)
    {
        if(t=='!')
        {
            ll idx1=lower_bound(val.begin(),val.end(),p[a])-val.begin();
            ll idx2=lower_bound(val.begin(),val.end(),b)-val.begin();
            p[a]=b;
            update(1,0,M-1,idx1 ,-1);
            update(1,0,M-1,idx2,1);
        }
        else
        {
            ll idx1=lower_bound(val.begin(),val.end(),a)-val.begin();
            ll idx2=lower_bound(val.begin(),val.end(),b)-val.begin();
            cout<<query(1,0,M-1,idx1,idx2)<<"\n";
        }
    }
 
 
}
 
 
 