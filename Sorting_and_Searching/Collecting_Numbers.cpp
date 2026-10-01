#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    vector<ll> p(N+1);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    ll sol=1;
    for(int i=1;i<N;i++)
    {   
        //cout<<p[i]<<" ";
        if(p[i]>p[i+1])
        {
            sol+=1;
        }
    }
    
    cout<<sol;
}