#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<array<ll,2>> v;
    for(int i=0;i<N;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back({a,-2});
        v.push_back({b,0});
    }
    sort(v.begin(),v.end());
    ll max_=0;
    ll cur_=0;
    for(auto [t,ti]:v)
    {
        cur_+=((-ti)-1);
        max_=max(max_,cur_);
    }
    cout<<max_;
 
 
}