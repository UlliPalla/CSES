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
    ll D=1;
    ll M=1;
    ll S=1;
    ll P=1;
    ll D_exp=1;
    ll MOD=1e9+7;
    cin>>N;
    for(int i=0;i<N;i++)
    {
        
        ll p,exp;
        cin>>p>>exp;
        D=(D*(exp+1)%MOD);
        M=(M*(fast_exp_mod(p,exp,MOD))%MOD);
        S=(S*(((fast_exp_mod(p,exp+1,MOD)-1+MOD)%MOD*fast_exp_mod(p-1,MOD-2,MOD))%MOD))%MOD;
        P=(fast_exp_mod(P,exp+1,MOD)*fast_exp_mod(p,((exp*(exp+1)/2)%(MOD-1)*D_exp)%(MOD-1),MOD))%MOD;
        D_exp=(D_exp*(exp+1))%(MOD-1);
    }
    cout<<D<<" "<<S<<" "<<P;
}