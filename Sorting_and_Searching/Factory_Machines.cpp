#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,T;
    cin>>N>>T;
    vector<ll> m(N);
    ll min_=LONG_LONG_MAX;
    for(int i=0;i<N;i++)
    {
        cin>>m[i];
        min_=min(min_,m[i]);
    }
    ll L=0;
    ll R=T*min_;
    ll best_=0;
    while(L<=R)
    {
        ll M=(L+R)/2;
        ll sum_=0;
        for(int i=0;i<N;i++)
        {
            sum_+=floor(M/m[i]);
        }
        if(sum_>=T)
        {
            R=M-1;
            best_=M;
        }
        else
        {
            L=M+1;
        }
 
    }
    cout<<best_;
}