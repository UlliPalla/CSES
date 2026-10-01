#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ll N,x;
    cin>>N>>x;
    map<ll,ll> mp;
    mp[0]=1;
    ll sum_=0;
    ll sol_=0;
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        sum_+=k;
        if(mp.count(sum_-x))
        {
            sol_+=mp[sum_-x];
            //cout<<x-k<<" "<<i<<" \n";
        }
        mp[sum_]+=1;
    }
    cout<<sol_;
 
}