#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N;
    cin>>N;
    vector<ll> a(N);
    ll max_=1;
    ll sol_=0;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        max_=max(max_,a[i]);
    }
    vector<ll> cnt(max_+1,0);
    for(int i=0;i<N;i++)
    {
        cnt[a[i]]+=1;
    }
    vector<ll> mo(max_+1,0);
    mo[1]=1;
    for(int i=0;i<=max_;i++)
    {
        if(mo[i]!=0)
        {
            for(int j=2*i;j<=max_;j+=i)
            {
                mo[j]-=mo[i];
            }
        }
    }
    for(int i=1;i<=max_;i++)
    {   
        ll S=0;
        if(mo[i]!=0)
        {
            
            for(int j=i;j<=max_;j+=i)
            {
                S+=cnt[j];
            }
        }
        sol_+=(mo[i]*(S)*(S-1)/2);
    }
    cout<< sol_;
}