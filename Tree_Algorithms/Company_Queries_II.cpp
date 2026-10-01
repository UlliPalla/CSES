#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
ll LCA(ll a,ll b,vector<ll> &depth,vector<vector<ll>> &up)
{   
    //cout<<"dsad";
    ll LOG=20;
    if(depth[a]<depth[b])
    {
        swap(a,b);
    }
    ll d=depth[a]-depth[b];
    for(int j=LOG-1;j>=0;j--)
    {
        if((d>>j)&1)
        {
            a=up[a][j];
        }
    }
    if(a==b)
    {
        return a;
    }
    for(int j=LOG-1;j>=0;j--)
    {   
        if(up[a][j]!=up[b][j])
        {
            if(up[a][j]!=-1 and up[b][j]!=-1)
            {
                a=up[a][j];
                b=up[b][j];
            }
        }
    }
    return up[a][0];
}
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //ifstream cin("input.txt");
    ll N,Q;
    ll INF=1e9;
    cin>>N>>Q;
    vector<ll> parent(N);
    vector<ll> depth(N,INF);
    depth[0]=0;
    ll LOG=20;
    vector<vector<ll>> grafo(N);
    vector<vector<ll>> up(N,vector<ll> (LOG+1));
    parent[0]=-1;
    up[0][0]=-1;
    for(int i=1;i<N;i++)
    {   
        ll a;
        cin>>a;
        parent[i]=a-1;
        up[i][0]=parent[i];
        grafo[i].push_back(a-1);
        grafo[a-1].push_back(i);
    }
    for(int step=0;step<LOG;step++)
    {
        for(int node=0;node<N;node++)
        {
            if(up[node][step]!=-1)
            {
                up[node][step+1]=up[up[node][step]][step];
            }
            else
            {
                up[node][step+1]=-1;
            }
        }
    }
    queue<ll> q;
    q.push(0);
    while(!q.empty())
    {
        ll node=q.front();
        q.pop();
        for(auto v:grafo[node])
        {
            if(depth[node]+1<depth[v])
            {
                depth[v]=depth[node]+1;
                q.push(v);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        //cout<<depth[i]<<" ";
    }
    for(int i=0;i<Q;i++)
    {   
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        ll lca=LCA(a,b,depth,up);
        cout<<lca+1<<"\n";
    }   
 
}