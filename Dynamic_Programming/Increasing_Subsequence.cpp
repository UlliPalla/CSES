#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> t(40);
 
void build(int v,int tl, int tr)
{
    if(tl==tr)
    {
        t[tl]=0;
    }
    else
    {
        int tm=(tr+tl)/2;
        build(2*v,tl,tm);
        build(2*v+1,tm+1,tr);
        t[v]=max(t[2*v],t[2*v+1]);
    }
}
int query(int v,int tl,int tr,int l,int r)
{
    if(l>r)
    {
        return 0;
    }
    else if(tl==l and tr==r)
    {
        return t[v];
    }
    else
    {
        int tm=(tl+tr)/2;
        return (max(
            query(2*v,tl,tm,l,min(r,tm)),
            query(2*v+1,tm+1,tr,max(l,tm+1),r)
        ));
    }
}
void update(int v,int tl,int tr, int idx,int val)
{
    if(tl==tr)
    {
        t[v]=max(val,t[v]);
    }
    else
    {   
        int tm=(tl+tr)/2;
        if(idx<=tm)
        {
            update(2*v,tl,tm,idx,val);
        }
        else
        {
            update(2*v+1,tm+1,tr,idx,val);
        }
        t[v]=max(t[2*v],t[2*v+1]);
    }
}
 
int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<ll> a(N);
    vector<ll> p(N);
    ll max_=0;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        p[i]=a[i];
    }
 
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    int M=a.size();
    vector<ll> DP(N+1);
    t.assign(4*M,0);
    //build(1,0,M-1)
    for(int i=0;i<N;i++)
    {   
        ll idx=lower_bound(a.begin(),a.end(),p[i])-a.begin();
        DP[idx]=1+query(1,0,M-1,0,idx-1);
        update(1,0,M-1,idx,DP[idx]);
        max_=max(DP[idx],max_);
    }
    cout<<max_;
 
}
 
 
 