#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N=1;
    cin>>N;
    ll MOD=1e9+7;
    ll INV2=500000004;
    ll sol_=0;
    for(ll L=1,R;L<=N;L=R+1)
    {   
        
        ll q=floor(N/L);
        R=floor(N/q);
        ll p=(((R-L+1)%MOD)*((L+R)%MOD))%MOD;
        p=(p*INV2)%MOD;
        ll p_=((q%MOD)*p)%MOD;
        sol_=(p_+sol_)%MOD;
    }
    cout<<sol_;
    
 
    
}