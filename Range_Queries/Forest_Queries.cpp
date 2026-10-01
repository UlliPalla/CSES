#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
 
int main()
{   
    //ifstream cin("input.txt");
    int N,Q;
    cin>>N>>Q;
    vector<vector<ll>> f(N+1,vector<ll> (N+1,0));
    vector<vector<ll>> pref(N+1,vector<ll> (N+1,0));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            char x;
            cin>>x;
            if(x=='*')
            {
                f[i][j]=1;
            }
        }
    }
    for(int i=1;i<=N;i++)
    {
        pref[i][0]=f[i][0];
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
           pref[i][j]=pref[i][j-1]+f[i][j];
        }
        //cout<<"\n";
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
           pref[i][j]+=pref[i-1][j];
        }
        //cout<<"\n";
    }
 
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            //cout<<pref[i][j];
        }
        //cout<<"\n";
    }
    for(int i=0;i<Q;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        ll x_max=max(x1,x2);
        ll x_min=min(x1,x2);
        ll y_max=max(y1,y2);
        ll y_min=min(y1,y2);
        //cout<<x_max<<" "<<y_max<<"\n"<<x_min-1<<" "<<y_min-1<<"\n"<<x_max<<" "<<y_min-1<<"\n"<<x_min-1<<" "<<y_max<<"\n";
        cout<<pref[x_max][y_max]+pref[x_min-1][y_min-1]-pref[x_max][y_min-1]-pref[x_min-1][y_max]<<"\n";
    }
 
}