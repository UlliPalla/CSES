#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    //ifstream cin("input.txt");
    int N,M;
    cin>>N>>M;
    vector<ll> P(N);
    for(int i=0;i<N;i++)
    {
        cin>>P[i];
    }
    ll INF=1e15;
    vector<array<ll,2>> DP(1<<(N),{INF,INF});
    DP[0]={1,0};
    for(int subset=1;subset<(1<<N);subset++)
    {
        for(int p=0;p<N;p++)
        {   
            if((subset>>p)&1)
            {
                auto [r,w]=DP[subset^(1<<p)];
                if(w+P[p]<=M)
                {
                    w+=P[p];
                }
                else
                {
                    r+=1;
                    w=min(w,P[p]);
                }
                DP[subset]=min(DP[subset],{r,w});
                
            }
        }
        //cout<<subset<<" "<<DP[subset][0]<<" "<<DP[subset][1]<<" \n";
    }
    cout<<DP[(1<<N)-1][0];
    
 
}