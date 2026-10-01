#include <bits/stdc++.h>
#define ll long long 
using namespace std;
 
 
int main()
{
    //ifstream cin("input.txt");
    ll N,M;
    cin>>N>>M;
    vector<vector<ll>> grafo(N);
    for(int i=0;i<M;i++)
    {
        ll a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    ll st_=-1;
    ll end_=-1;
    bool gd=false;
    vector<ll> parent(N,-1);
    vector<bool> visto(N,false);
    for(int i=0;i<N;i++)
    {
        if(visto[i])
        {
            continue;
        }
        stack<array<ll,2>> st;
        st.push({i,i});
        while(!st.empty())
        {
            auto [node,p_]=st.top();
            st.pop();
            if(!visto[node])
            {
                visto[node]=true;
                for(auto v:grafo[node])
                {
                    if(v!=p_ and visto[v])
                    {
                        gd=true;
                        st_=node;
                        end_=v;
                        break;
                    }
                    if(!visto[v])
                    {
                        st.push({v,node});
                        parent[v]=node;
                    }
                }
            }
        }
    }
    if(gd)
    {
        vector<ll> sol;
        ll cur_=st_;
        sol.push_back(end_);
        while(cur_!=end_)
        {
            sol.push_back(cur_);
            cur_=parent[cur_];
        }
        sol.push_back(cur_);
        cout<<sol.size()<<"\n";
        for(auto &x:sol)
        {
            cout<<x+1<<" ";
        }
        
    }
    else
    {
        cout<<"IMPOSSIBLE"<<"\n";
    }
 
 
 
}