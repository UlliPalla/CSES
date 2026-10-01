#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAX_N=2*1e5;
vector<ll> parent(MAX_N);
vector<ll> siz(MAX_N);
 
void DSU(ll n)
{
    parent.resize(n);
    siz.resize(n);
    for(int i=0;i<n;i++)
    {
        siz[i]=1;
        parent[i]=i;
    }
}
ll get_root(ll v)
{
    if(parent[v]==v)
    {    
        return v;
    }
    return parent[v]=get_root(parent[v]);
}
 
bool merge(ll a,ll b)
{
    a=get_root(a);
    b=get_root(b);
    if(a!=b)
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
        return true;
    }
    return false;
}
 
int main()
{
    //ifstream cin("input.txt");
    ll N,M;
    cin>>N>>M;
    vector<array<ll,3>> arc;
    vector<vector<array<ll,2>>> grafo(N);
    for(int i=0;i<M;i++)
    {
        ll a,b,w;
        cin>>a>>b>>w;
        a-=1;
        b-=1;
        grafo[a].push_back({b,w});
        grafo[b].push_back({a,w});
        arc.push_back({w,a,b});
    }
    ll w_=0;
    ll arc_=0;
    DSU(N);
    sort(arc.begin(),arc.end());
    for(auto [w,a,b]:arc)
    {
        if(merge(a,b))
        {
            w_+=w;
            arc_+=1;
        }
    }
    if(arc_==N-1)
    {
        cout<<w_;
    }
    else
    {
        cout<<"IMPOSSIBLE";
    }
 
 
}