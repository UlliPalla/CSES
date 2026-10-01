#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5+3;
struct Node
{
    ll sum;
    ll pref;
    ll suff;
    ll best;
 
};
 
 
vector<Node> tree(4*MAX_N+5);
 
Node merge(Node dx,Node sx)
{
    Node res;
    res.sum=(dx.sum+sx.sum);
    res.pref=max(dx.pref,dx.sum+sx.pref);
    res.suff=max(sx.suff,sx.sum+dx.suff);
    res.best=max({dx.best,sx.best,dx.suff+sx.pref});
    return res;
}
 
void build(ll v,ll tl,ll tr,vector<ll> &copy)
{
    if(tl==tr)
    {
        tree[v].sum=copy[tl];
        tree[v].pref=max((ll)0,copy[tl]);
        tree[v].suff=tree[v].pref;
        tree[v].best=tree[v].pref;
    }
    else
    {
        ll tm=(tl+tr)/2;
        build(2*v,tl,tm,copy);
        build(2*v+1,tm+1,tr,copy);
        tree[v]=merge(tree[2*v],tree[2*v+1]);
    }
}
 
void update(ll v, ll tl ,ll tr,ll idx,ll val)//assign
{
    if(tl==tr)
    {
        tree[v].sum=val;
        tree[v].pref=max((ll)0,val);
        tree[v].suff=tree[v].pref;
        tree[v].best=tree[v].pref;
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
        ll a,b;
        cin>>a>>b;
        update(1,0,N-1,a-1,b);
        cout<<tree[1].best<<"\n";
    }
}