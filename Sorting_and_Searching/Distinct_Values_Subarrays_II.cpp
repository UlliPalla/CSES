#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ll N,k;
    cin>>N>>k;
    ll cur_=0;
    ll sol_=0;
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    ll L=0;
    map <ll ,ll> f;
    for(int R=0;R<N;R++)
    {
        if(f[a[R]]==0)
        {
            cur_+=1;
        }
        f[a[R]]+=1;
        while(cur_>k)
        {
            f[a[L]]-=1;
            if(f[a[L]]==0)
            {
                cur_-=1;
            }
            L+=1;
        }
        sol_+=(R-L+1);
    }
    cout<<sol_;
}