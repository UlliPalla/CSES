#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ll N;
    cin>>N;
    map<ll,ll> mp;
    mp[0]=1;
    ll sum_=0;
    ll sol_=0;
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        sum_+=k;
        if(mp.count((N+(sum_)%N)%N))
        {
            sol_+=mp[(N+(sum_)%N)%N];
            //cout<<x-k<<" "<<i<<" \n";
        }
        mp[(N+(sum_)%N)%N]+=1;
    }
    cout<<sol_;
 
}