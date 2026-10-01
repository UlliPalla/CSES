#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    //ifstream cin("input.txt");
    ll N,Q;
    cin>>N>>Q;
    vector<ll> parent(N);
    ll LOG=20;
    vector<vector<ll>> up(N,vector<ll> (LOG));
    parent[0]=-1;
    up[0][0]=-1;
    for(int i=1;i<N;i++)
    {   
        ll a;
        cin>>a;
        parent[i]=a-1;
        up[i][0]=parent[i];
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
    for(int q=0;q<Q;q++)
    {   
        bool gd=true;
        int a,b;
        cin>>a>>b;
        ll cur_=a-1;
        for(int j=0;j<LOG;j++)
        {
            if((b>>j)&1)
            {
                cur_=up[cur_][j];
            }
            if(cur_==-1)
            {
                cout<<-1<<"\n";
                gd=false;
                break;
                
            }
        }
        if(gd)
        {
            cout<<cur_+1<<"\n";
        }
    }
    
}