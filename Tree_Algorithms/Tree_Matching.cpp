#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<vector<ll>> grafo(N);
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    stack<ll> st;
    vector<ll> parent(N,-1);
    vector<bool> visto(N,false);
    vector<ll> num_f(N);
    //visto[0]=true;
    st.push(0);
    while(!st.empty())
    {
        ll node=st.top();
        st.pop();
        if(visto[node])
        {
            continue;
        }
        else
        {   
            visto[node]=true;
            for(auto v:grafo[node])
            {
                if(!visto[v])
                {
                    parent[v]=node;
                    num_f[node]+=1;
                    st.push(v);
                }
            }
        }
    }
    for(int i=0;i<N;i++)
    {
        //cout<<parent[i];
    }
    queue<ll> que;
    for(int i=0;i<N;i++)
    {
        if(num_f[i]==0)
        {
            que.push(i);
            //cout<<i<<" ";
        }
    }
    ll max_=0;
    vector<array<ll,2>> DP(N,{0,0});
    while(!que.empty())
    {
        ll node=que.front();
        que.pop();
        ll p=parent[node];
        if(p!=-1)
        {
            DP[p][0]+=(max(DP[node][0],DP[node][1]));
            max_=max(max_,DP[p][0]);
            num_f[p]-=1;
            if(num_f[p]==0)
            {
                for(auto v:grafo[p])
                {   
                    if(v==parent[p])
                    {
                        continue;
                    }
                    DP[p][1]=max((1+DP[p][0]+DP[v][0]-max(DP[v][0],DP[v][1])),DP[p][1]);
                    max_=max(max_,DP[p][1]);
                }
                que.push(p);
                //cout<<DP[p][0]<<" "<<DP[p][1]<<" "<<p<<"\n";
            }
        }
    }
    cout<<max_;
 
}