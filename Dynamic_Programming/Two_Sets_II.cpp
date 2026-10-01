#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    int MOD=1e9+7;
    //ifstream cin("input.txt");
    int N=7;
    cin>>N;
    ll sum_=(N+1)*N/2;
    if(sum_%2==0)
    { 
        vector<ll> DP(sum_+1,0);
        DP[0]=1;
        
        for(int c=1;c<N;c++)
        {
            for(int i=sum_/2-c;i>=0;i--)
            {   
                if(DP[i]>0)
                {
                    DP[i+c]=(DP[i]+DP[i+c])%MOD;
                }
            }
        }
        cout<<DP[sum_/2];
    }
    else
    {
        cout<<0;
    }
    return 0;
}