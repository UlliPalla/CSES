#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    ll MOD=1e9+7;
    int N;
    cin>>N;
    map<ll,ll> f;
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        if(f.count(k))
        {
            f[k]+=1;
        }
        else
        {
            f.insert({k,1});
        }
 
    }
    ll sol_=1;
    for(auto [a,b]:f)
    {
        sol_*=(1+b);
        sol_%=MOD;
    }
    cout<<sol_-1;
}