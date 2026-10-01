#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    //ifstream cin("input.txt");
    string a,b;
    cin>>a>>b;
    ll INF=1e9+7;
    ll N=a.length();
    ll M=b.length();
    vector<vector<ll>> DP(N+1,vector<ll>(M+1,INF));
    for(int i=0;i<=M;i++)
    {
        DP[0][i]=i;
    }
    for(int j=0;j<=N;j++)
    {
        DP[j][0]=j;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {   
            DP[i][j]=min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1]))+1;
            if(a[i-1]==b[j-1])
            {
                DP[i][j]=DP[i-1][j-1];
            }
        }
    }
    cout<<DP[N][M];
 
    return 0;
}