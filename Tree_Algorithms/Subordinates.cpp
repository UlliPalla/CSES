#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N;
    cin>>N;
    vector<vector<ll>> grafo(N);
    queue<ll> que;
    vector<ll> sol(N,0);
    vector<ll> num_f(N);
    vector<ll> parent(N);
    for(int i=1;i<N;i++)
    {
        ll a;
        cin>>a;
        grafo[i].push_back(a-1);
        grafo[a-1].push_back(i);
        num_f[a-1]+=1;
        parent[i]=a-1;
    }
    parent[0]=-1;
    for(int i=0;i<N;i++)
    {
        if(num_f[i]==0)
        {
            que.push(i);
        }
    }
    while(!que.empty())
    {
        ll node=que.front();
        que.pop();
        ll p=parent[node];
        if(p!=-1)
        {
            num_f[p]-=1;
            sol[p]+=(sol[node]+1);
            if(num_f[p]==0)
            {
                que.push(p);
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<sol[i]<<" ";
    }   
}