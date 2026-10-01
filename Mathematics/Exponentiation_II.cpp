#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
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
 
 
int main()
{   
    ll N;
    cin>>N;
    ll mod=1e9+7;
    for(int i=0;i<N;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        ll p=fast_exp_mod(b,c,mod-1);
        cout<<fast_exp_mod(a,p,mod)<<"\n";
    }
}