#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<array<ll,3>> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i;
 
    }
    sort(a.begin(),a.end(),[](const auto&a,const auto&b)
    {
        if(a[0]==b[0])
        {
            return a[1]>b[1];
        }
        else
        {
            return a[0]<b[0];
        }
    });
    
 
    vector<ll> sol_r(N);
 
    ll max_=0;
    for(int i=0;i<N;i++)
    {   
  
        if(a[i][1]<=max_)
        {   
            sol_r[a[i][2]]=1;
        }
        else
        {
            max_=a[i][1];
            sol_r[a[i][2]]=0;
        }
    }
 
    sort(a.begin(),a.end(),[](const auto&a,const auto&b)
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1];
        }
        else
        {
            return a[0]>b[0];
        }
    });
 
 
 
    vector<ll> sol_(N);
    ll min_=LONG_LONG_MAX;
    for(int i=0;i<N;i++)
    {
        if(a[i][1]>=min_)
        {
            sol_[a[i][2]]=1;
        }
        else
        {
            min_=a[i][1];
            sol_[a[i][2]]=0;
        }
    }
    for(int i=0;i<N;i++)
    {
        cout<<sol_[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<N;i++)
    {
        cout<<sol_r[i]<<" ";
    }
 
 
}