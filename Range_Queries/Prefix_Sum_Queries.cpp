#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*2e5+1;
 
 
struct Node
{
    ll sum;
    ll max_pref;
};
vector<Node> tree(4*MAX_N+5);
 
Node merge(Node a,Node b)
{   
    Node res;
    res.sum=(a.sum+b.sum);
    res.max_pref=max(a.max_pref,a.sum+b.max_pref);
    return res;
}
 
void build(ll v,ll tl ,ll tr,vector<ll> &copy)
{
    if(tl==tr)
    {
        tree[v].sum=copy[tl];
        tree[v].max_pref=max((ll)0,copy[tl]);
 
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
}
 
void update(ll v,ll tl ,ll tr,ll idx,ll val)
{
    if(tl==tr)
    {
        tree[v].sum=val;
        tree[v].max_pref=max((ll)0,val);
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
        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
}
 
Node query(ll v,ll tl ,ll tr ,ll l ,ll r)
{
    if(l>r)
    {
        return {0,0};
    }
    else if(tl==l and tr==r)
    {
        return tree[v];
    }
    else
    {
        ll tm=(tl+tr)/2;
        return merge(query(2*v,tl,tm,l,min(tm,r)),query(2*v+1,tm+1,tr,max(l,tm+1),r));
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
        int s;
        cin>>s;
        if(s==1)
        {   
            int a,b;
            cin>>a>>b;
            update(1,0,N-1,a-1,b);
        }
        else
        {
            int a,b;
            cin>>a>>b;
            cout<<query(1,0,N-1,a-1,b-1).max_pref<<"\n";
        }
    }
 
 
}