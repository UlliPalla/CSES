#define ll long long
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ll N;
    cin>>N;
    ll K;
    cin>>K;
    ll sol_=0;
    vector<ll> primes(K);
    for(int i=0;i<K;i++)
    {
        cin>>primes[i];
    }
    
    for(ll mask=1;mask<(1<<K);mask++)
    {
        ll p_=1;
        ll bit_=0;
        bool gd=true;
        for(int i=0;i<K;i++)
        {
            if((mask>>i)&1)
            {
                bit_+=1;
                if(p_>N/primes[i])
                {
                    gd=false;
                    break;
                }
                p_*=primes[i];
                
            }
        }
        if(gd)
        {
            if(bit_%2==1)
            {
                sol_+=(N/p_);
            }
            else 
            {
                sol_-=(N/p_);
            }
        }
    }
    cout<<sol_;
}