#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
 
    //ifstream cin("input.txt");
    int N;
    cin>>N;
    ll INF=1e13+7;
    vector<ll> a;
    
    for(int i=0;i<N;i++)
    {   
        int k;
        cin>>k;
        a.push_back(k);
    }
    vector<vector<ll>> DP(N+1,vector<ll>(N+1,INF));
    vector<ll> pref(N+1,0);
    vector<ll> suff(N+1,0);
    for(int i=1;i<=N;i++)
    {
        pref[i]=pref[i-1]+a[i-1];
    }//pref con 1index
    
    
    
    
    for(int i=N;i>=0;i--)
    {
        for(int j=i;j<N;j++)
        {
            if(i==j)
            {
                DP[i][j]=a[i];
            }
            else
            {
                DP[i][j]=pref[j+1]-pref[i]-min(DP[i+1][j],DP[i][j-1]);
            }
        }
    }
    cout<<DP[0][N-1];
    
}