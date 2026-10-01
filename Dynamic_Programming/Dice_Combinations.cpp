#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    int N;
    cin>>N;
    ll MOD=1e9+7;
    vector<int> DP(N+1,0);
    DP[0]=1;
    for(int i=0;i<=N;i++)
    {
        
        for(int j=1; j<7;j++)
        {   
            if(i-j>=0)
            {
                DP[i]+=DP[i-j];
                DP[i]%=MOD; 
            }
            
        }
    }
    
    cout<<DP[N];
}