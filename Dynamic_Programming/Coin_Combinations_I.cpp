#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
 
    //ifstream cin("input.txt");
    int N,T;
    cin>>N>>T;
    vector<ll> c;
    
    for(int i=0;i<N;i++)
    {   
        int k;
        cin>>k;
        c.push_back(k);
    }
    
    ll MOD=1e9+7;
    vector<ll> DP(T+1,0);
    DP[0]=1;
    for(int i=1;i<=T;i++)
    {
        for(auto co:c)
        {   
            if(i-co>=0)
            {
                DP[i]+=DP[i-co];
                DP[i]%=MOD;
            }
        }
    }
    cout<<DP[T];
    
    
}