#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ll N,M;
    cin>>N>>M;
    vector<ll> indeg(N,0);
    vector<vector<ll>> grafo(N);
    for(int i=0;i<M;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        indeg[b]+=1;
        grafo[a].push_back(b);
    }
    vector<ll> DP(N,0);
    DP[0]=1;
    queue<ll> q;
    for(int i=0;i<N;i++)
    {
        if(indeg[i]==0)
        {
            q.push(i);
        }
    }
    ll MOD=1e9+7;
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(auto v:grafo[node])
        {
            DP[v]+=DP[node];
            DP[v]%=MOD; 
            indeg[v]-=1;
            if(indeg[v]==0)
            {
                q.push(v);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        //cout<<DP[i]<<" ";
    }
    cout<<DP[N-1];
}