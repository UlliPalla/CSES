#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
ll RMQ(ll L ,ll R,vector<vector<ll>> &table)
{
    ll lg=log2(R-L+1);
    return min(table[L][lg],table[R-(1<<lg)+1][lg]);
}
 
 
int main()
{
    //ifstream cin("input.txt");
    ll N,Q;
    cin>>N>>Q;
    ll LOG=30;
    vector<vector<ll>> table(N+1,vector<ll> (LOG+1,1e14));
    for(int i=0;i<N;i++)
    {
        cin>>table[i][0];
    }
    for(int step=0;step<LOG;step++)
    {
        for(int i=0;i<N;i++)
        {
            ll p_=1<<step;
            if(i+p_<N)
            {
                table[i][step+1]=min(table[i][step],table[i+p_][step]);
            }
            else
            {
                table[i][step+1]=table[i][step];
            }
        }
    }
    for(int i=0;i<Q;i++)
    {
        ll a,b;
        cin>>a>>b;
        cout<<RMQ(a-1,b-1,table)<<"\n";
    }
 
 
}