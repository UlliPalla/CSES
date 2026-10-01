#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MOD=1e9+7;
 
int main()
{   
    ll MAX_N=1e6;
    ll N;
    ll max_=0;
    cin>>N;
    vector<ll> cnt(MAX_N+1,0);
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        cnt[a[i]]+=1;
        max_=max(max_,a[i]);
    }
    for(ll i=max_;i>=0;i--)
    {
        ll cnt_=0;
        for(ll j=i;j<=max_;j+=i)
        {
            cnt_+=cnt[j];
        }
        if(cnt_>=2)
        {
            cout<<i<<"\n";
            break;
        }
    }
}