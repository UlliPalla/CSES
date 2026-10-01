#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
    //ifstream cin("input.txt");
    int N;
    ll INF=1e9;
    cin>>N;
    vector<ll> DP(N+1,INF);
    DP[0]=0;
    
    for(int i=0;i<=N;i++)
    {
        ll t=i;
        while(t!=0)
        {
            ll mod=t%10;
            if(i-mod>=0)
            {
                DP[i]=min(DP[i],DP[i-mod]+1);
            }
            t=(t-mod)/10;
        }    
        
    }
   
    cout<<DP[N];
}