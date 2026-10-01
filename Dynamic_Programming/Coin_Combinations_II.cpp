#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
 
int main()
{
    //ifstream cin("input.txt");
    ll N,K;
 
    cin>>N>>K;
    vector<ll> C(N);
    for(int i=0;i<N;i++)
    {
        cin>>C[i];
    }
    ll MOD=1e9+7;
    vector<ll> DP(K+1,0);
    DP[0]=1;
    for(auto &x:C)
    {
        for(int i=1;i<=K;i++)
        {
            if(i-x>=0)
            {
                DP[i]+=DP[i-x];
                DP[i]%=MOD;
            }
        }
    }
    cout<<DP[K];
}