#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    ll MOD=1e9+7;
    int N;
    cin>>N;
    vector<ll> D(N+2);
    D[0]=0;
    D[1]=1;
    for(int i=2;i<N;i++)
    {
        D[i]=(i*(D[i-1]+D[i-2])%MOD);
    }
    cout<<D[N-1];
 
}