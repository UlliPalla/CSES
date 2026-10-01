#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
 
    //ifstream cin("input.txt");
    int N,M;
    cin>>N>>M;
    ll INF=1e9+7;
    vector<vector<ll>> DP(N+1,vector<ll>(M+1,INF));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            if(i==j)
            {
                DP[i][j]=0;
            }
            else
            {
                for(int h=1;h<i;h++)
                {
                   DP[i][j]=min(DP[h][j]+DP[i-h][j]+1,DP[i][j]);
                }
                for(int v=1;v<j;v++)
                {
                   DP[i][j]=min(DP[i][v]+DP[i][j-v]+1,DP[i][j]);
                }
            }
        }
    }
    cout<<DP[N][M];
    return 0;
}