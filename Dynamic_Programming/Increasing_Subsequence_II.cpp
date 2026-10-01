#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll> t;
const int MOD=1e9+7;
ll query(int v,int tl,int tr,int l,int r)
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
        return (
            query(2*v,tl,tm,l,min(r,tm))+
            query(2*v+1,tm+1,tr,max(l,tm+1),r)
        )%MOD;
    
    }
}
void update(int v,int tl,int tr,int idx,ll val)
{
    if(tl==tr)
    {
        t[v]=(t[v]+val)%MOD;
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
        t[v]=(t[2*v]+t[2*v+1])%MOD;
    }
}
 
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    vector<ll> p(N);
 
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        p[i]=a[i];
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ll M=a.size();
    t.assign(4*M+1,0);
    for(int i=0;i<N;i++)
    {
        int j=lower_bound(a.begin(),a.end(),p[i])-a.begin();
        auto DP=query(1,0,M-1,0,j-1);
        update(1,0,M-1,j,(DP+1)%MOD);
        
    }
    cout<<query(1,0,M-1,0,M-1);
    
}