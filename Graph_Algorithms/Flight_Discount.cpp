#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{
    //ifstream cin("test_input(1).txt");
    ll N,M;
    cin>>N>>M;
    vector<vector<array<ll,2>>> grafo(N);
    for(int i=0;i<M;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a-=1;
        b-=1;
        grafo[a].push_back({b,c});
    }
    vector<array<ll,2>> dist(N,{LONG_LONG_MAX,LONG_LONG_MAX});
    dist[0]={0,0};
    priority_queue<array<ll,3>> pq;
    pq.push({0,0,1});
    while(!pq.empty())
    {
        auto [d,node,s]=pq.top();
        d=-d;
        pq.pop();
        if(d>dist[node][s])
        {
            continue;
        }
        for(auto [v,w]:grafo[node])
        {
            if(s==0 and dist[v][0]>dist[node][0]+w)
            {
                dist[v][0]=dist[node][0]+w;
                pq.push({-dist[v][0],v,0});
            }
            if(s==1 and dist[v][1]>dist[node][1]+w)
            {
                dist[v][1]=dist[node][1]+w;
                pq.push({-dist[v][1],v,1});
 
            }
            if(s==1 and dist[v][0]>dist[node][1]+floor(w/2))
            {
                dist[v][0]=dist[node][1]+floor(w/2);
                pq.push({-dist[v][0],v,0});
                
            }
        }
    }
    cout<<dist[N-1][0];
 
}