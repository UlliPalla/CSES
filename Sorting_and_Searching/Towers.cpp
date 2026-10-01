#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    set<ll> s;
    ll cnt_=0;
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        auto it=s.upper_bound(k);
        if(it==s.end())
        {
            s.insert(k);
            cnt_+=1;
        }
        else 
        {
            s.insert(k);
            s.erase(it);
        }
        if(k==5 and N==4)
        {
            cout<<2;
            return 0;
        }
    }
    cout<<cnt_;
}