#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N=1e6+1;
 
 
ll fast_exp_mod(ll base,ll exp,ll MOD)
{
    ll sol_=1;
    while(exp>0)
    {
        if(exp%2==1)
        {
            sol_=(sol_*base)%MOD;
        }
        base=(base*base)%MOD;
        exp/=2;
    }
    
    return sol_;
}
 
ll bino(ll a,ll b,vector<ll> &fact,vector<ll> &invfact,ll MOD)
{
    ll sol_=1;
    sol_=(1LL*sol_*fact[a]*invfact[b])%MOD;
    sol_=(1LL*sol_*invfact[a-b])%MOD;
    return sol_;
}    
int main()
{   
    ll MOD=1e9+7;
    int N;
    cin>>N;
    if(N%2==1)
    {
        cout<<0;
        return 0;
    }
    N/=2;
    vector<ll> invfact(2*MAX_N+1,1);
    vector<ll> fact(2*MAX_N+1,1);
    for(int i=0;i<MAX_N;i++)
    {
        fact[i+1]=((i+1)*fact[i])%MOD;
        invfact[i+1]=fast_exp_mod(fact[i+1],MOD-2,MOD);
    }
    
    cout<<(bino(2*N,N,fact,invfact,MOD)*fast_exp_mod(N+1,MOD-2,MOD))%MOD<<"\n";
    
 
}