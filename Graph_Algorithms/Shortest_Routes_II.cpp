#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,M,Q;
    cin>>N>>M>>Q;
    vector<vector<ll>> grafo(N,vector<ll> (N,LONG_LONG_MAX));
    for(int i=0;i<N;i++)
    {
        grafo[i][i]=0;
    }
    for(int i=0;i<M;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a-=1;
        b-=1;
        grafo[a][b]=min(grafo[a][b],c);
        grafo[b][a]=min(grafo[b][a],c);
    }
    for(int k=0;k<N;k++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                    if(grafo[i][k]!=LONG_LONG_MAX and grafo[k][j]!=LONG_LONG_MAX)
                    {
                        grafo[i][j]=min(grafo[i][k]+grafo[k][j],grafo[i][j]);
                    }
            }
        }
    }
    for(int i=0;i<Q;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(grafo[a][b]==LONG_LONG_MAX)
        {
            cout<<-1<<"\n";
        }
        else
        {
            cout<<grafo[a][b]<<"\n";
        }
    }
 
 
}