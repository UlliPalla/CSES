#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
 
ll fast_exp(ll b,ll e,ll MOD)
{
    ll sol_=1;
    while(e>0)
    {   
        if(e%2==1)
        {
            sol_*=b;
            sol_%=MOD;
        }
        b*=b;
        b%=MOD;
        e/=2;
    }
    return sol_;
}
 
 
int main()
{
    //ifstream cin("input.txt");
    ll T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<fast_exp(a,b,1e9+7)<<"\n";
    }
}