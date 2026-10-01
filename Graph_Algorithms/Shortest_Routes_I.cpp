#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    //ifstream cin("input.txt");
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
        //grafo[b].push_back({a,c});
    }
    vector<ll> dist(N,1e14);
    dist[0]=0;
    priority_queue<array<ll,2>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        auto [d,node]=pq.top();
        pq.pop();
        d=-d;
        if(d>dist[node])
        {
            continue;
        }
        for(auto [v,w]:grafo[node])
        {
            if(w+d<dist[v])
            {
                dist[v]=d+w;
                pq.push({-dist[v],v});
            }
        }
    }
    for(auto &x:dist)
    {
        if(x==1e14)
        {
            x=-1;
        }
        cout<<x<<" ";
    }
 
}