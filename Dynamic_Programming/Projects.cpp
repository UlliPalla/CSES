#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() 
{
    //ifstream cin("input.txt");
    ll N;
    cin>>N;
    vector<array<ll,3>> proj;
    vector<ll> date;
    ll max_g=0;
    for(int i=0;i<N;i++)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        proj.push_back({a,b,c});
        if(b>max_g)
        {
            max_g=b;
        }
        date.push_back(a);
        date.push_back(b);
    }
    sort(date.begin(),date.end());
    date.erase(unique(date.begin(),date.end()),date.end());
    ll M=date.size();
    vector<vector<array<ll,3>>> proj_end_at(M+1);
    for(int i=0;i<N;i++)
    {   
        ll st=lower_bound(date.begin(),date.end(),proj[i][0])-date.begin()+1;
        ll end=lower_bound(date.begin(),date.end(),proj[i][1])-date.begin()+1;
        proj_end_at[end].push_back({st,end,proj[i][2]});
        //cout<<i<<" "<<proj[i][0]<<" "<<proj[i][1]<<" "<<proj[i][2]<<"\n";
    }
    ll INF=1e12;
    vector<ll> DP(M+1,-INF);
    DP[0]=0;
    for(int i=1;i<=M;i++)
    {   
 
        for(auto [a,b,p]:proj_end_at[i])
        {
            DP[i]=max(DP[i],DP[a-1]+p);
        }
        DP[i]=max(DP[i],DP[i-1]);
        //cout<<DP[i]<<" ";
    }
    cout<<DP[M];
}