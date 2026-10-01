#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input.txt");
    ll N,M;
    cin>>N>>M;
    ll MOD=1e9+7;
    vector<ll> a(N);
    for(int i=0; i<N;i++)
    {
        cin>>a[i];
        //cout<<a[i]<<" ";
    }
    vector<vector<ll>> DP(N+1,vector<ll> (M+2,0));
    if(a[0]==0)
    {
        fill(DP[0].begin(),DP[0].end(),1);
    }
    
    else
    {
        DP[0][a[0]]=1;
    }
    DP[0][0]=0;
    DP[0][M+1]=0;
    for(int i=1;i<N;i++)
    {   
        //cout<<a[i]; 
        if(a[i]==0)
        {  
            //cout<<1;
            for(int v=1;v<=M;v++)
            {
            
                DP[i][v]=(DP[i][v]+(DP[i-1][v]+DP[i-1][v-1]+DP[i-1][v+1])%MOD);
                //cout<<DP[i][v];
            }
        }
        else 
        {
            DP[i][a[i]]=(DP[i-1][a[i]-1]+DP[i-1][a[i]]+DP[i-1][a[i]+1]%MOD);
        }
    }
    ll sol_=0;
    for(int i=1;i<=M;i++)
    {
        sol_=(sol_+DP[N-1][i])%MOD;
        //cout<<DP[N-1][i]<<" ";
    }
    cout<<sol_;
 
}