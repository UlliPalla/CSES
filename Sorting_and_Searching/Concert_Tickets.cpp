#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    ll N,M;
    cin>>N>>M;
    multiset<ll> t;
    vector<ll> m(M);
    for(int i=0;i<N;i++)
    {   
        ll k;
        cin>>k;
        t.insert(k);
    }
    for(int i=0;i<M;i++)
    {
        cin>>m[i];
    }
    for(int i=0;i<M;i++)
    {
        auto it=t.upper_bound(m[i]);
        if(it==t.begin())
        {
            cout<<-1<<" ";
            continue;
        }
        else 
        {     
            it =prev(it);
           
            cout<<*it<<" \n";
            t.erase(it);
        }
    }
}