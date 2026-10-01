#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N=1e6+10;
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin>>N;
    vector<ll> div(MAX_N+1,0);
    for(ll i=1;i<MAX_N;i++)
    {
        for(ll j=i;j<=MAX_N;j+=i)
        {
            div[j]+=1;
        }
    }
    for(int i=0;i<N;i++)
    {
        ll x;
        cin>>x;
        cout<<div[x]<<"\n";
    }
 
    
}