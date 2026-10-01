#define ll long long
#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ll N,x;
    cin>>N>>x;
    multiset<ll> p;
    for(int i=0;i<N;i++)
    {   
        ll k;
        cin>>k;
 
        p.insert(k);
    }
    ll cnt_=0;
    while(!p.empty())
    {   
        if(p.size()==1)
        {
            cnt_+=1;
            break;
        }
        else if(*p.rbegin()+*p.begin()<=x)
        {   
            cnt_+=1;
            p.erase(p.find(*p.rbegin()));
            p.erase(p.find(*p.begin()));
        }
        else
        {
            cnt_+=1;
            p.erase(p.find(*p.rbegin()));
        }
    }
    cout<<cnt_;
}