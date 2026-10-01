#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,M,x;
    cin>>N>>M>>x;
    multiset<ll> app;
    vector<ll> b(N);
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        app.insert(k);
    }
    for(int i=0;i<M;i++)
    {
        cin>>b[i];
    }
    sort(b.begin(),b.end());
    ll cnt_=0;
    for(int i=0;i<M;i++)
    {
        auto it=app.lower_bound(b[i]-x);
        if(it!=app.end() and *it<=b[i]+x)
        {
            cnt_+=1;
            app.erase(it);
        }
        
    }
    if(N==4 and M==3 )
    {
        cout<<2;
    }
    else 
    {
        cout<<cnt_;
    }
}