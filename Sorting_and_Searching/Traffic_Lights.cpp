#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,Q;
    cin>>N>>Q;
 
    set<ll> tl;
    tl.insert(0);
    tl.insert(N);
    
    multiset<ll> dis;
    dis.insert(N);
    for(int i=0;i<Q;i++)
    {   
        ll k;
        cin>>k;
        auto it=tl.lower_bound(k);
        ll R=*it;
        ll L=*prev(it);
        dis.erase(dis.find(R-L));
        dis.insert(k-L);
        dis.insert(R-k);
        tl.insert(k);
        cout<<*dis.rbegin()<<" ";
    }
 
}