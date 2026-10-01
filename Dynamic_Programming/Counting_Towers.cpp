#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    ios::sync_with_stdio(0);
    cin.tie(0);
    int MAXN=1e7;
    int MOD=1e9+7;
    //ifstream cin("input.txt");
    int T;
    cin>>T;
    vector<ll> DP1(MAXN+1,0),DP2(MAXN+1,0);
        DP1[1]=1;
        DP2[1]=1;
        for(int i=2;i<=MAXN;i++)
        {
            DP1[i]=(4*DP1[i-1]+DP2[i-1])%MOD;
            DP2[i]=(DP1[i-1]+2*DP2[i-1])%MOD;
 
        }
    for(int t=0;t<T;t++)
    {
        int N;
        cin>>N;
        
        cout<<(DP1[N]+DP2[N])%MOD<<"\n";
    }
    return 0;
}