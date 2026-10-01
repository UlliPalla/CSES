#include <bits/stdc++.h>
#define ll long long 
using namespace std;
const int MAX_N=2*1e5;
vector<ll> parent(MAX_N,-1);
vector<ll> siz(MAX_N,1);
ll best_=1;
 
void DSU(ll N)
{
    parent.assign(N,0);
    siz.assign(N,1);
    for(int i=0;i<N;i++)
    {
        parent[i]=i;
    }
    best_=1;
}
 
 
ll get_parent(ll v)
{
    if(parent[v]==v)
    {
        return v;
    }
    return parent[v]=get_parent(parent[v]);
}
 
bool merge(ll a,ll b)
{
    a=get_parent(a);
    b=get_parent(b);
    if(a!=b)
    {
        if(siz[a]<siz[b])
        {
            swap(a,b);
        }
        parent[b]=a;
        siz[a]+=siz[b];
        best_=max(best_,siz[a]);
        
        return true;
    }
    return false;
}
 
 
 
int main()
{
    //ifstream cin("input.txt" );
    int N,M;
    cin>>N>>M;
    DSU(N);
    for(int i=0;i<M;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(merge(a,b))
        {
            N-=1;
        }
        cout<<N<<" "<<best_<<"\n";
    }
}