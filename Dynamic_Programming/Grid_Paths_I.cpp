#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<string> grid(N);
    for(int i=0;i<N;i++) cin>>grid[i];
    ll MOD=1e9+7;
    vector<vector<ll>> DP(N,vector<ll>(N,0));
    if(grid[0][0]=='*')
    {
        cout<<0;
        return 0;
    }
    DP[0][0]=1;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(grid[i][j]=='*')
            {
                DP[i][j]=0;
                continue;
            }
            if(i>0) DP[i][j]=(DP[i][j]+DP[i-1][j])%MOD;
            if(j>0) DP[i][j]=(DP[i][j]+DP[i][j-1])%MOD;
        }
    }
    cout<<DP[N-1][N-1];
    return 0;
}