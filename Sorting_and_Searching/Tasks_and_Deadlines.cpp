#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    vector<ll> d(N);
    ll sum_a=0,sum_d=0;
    for(int i=0;i<N;i++)
    {
        cin>>a[i]>>d[i];
        sum_a+=a[i];
        sum_d+=d[i];
    }
    ll cur_=0;
    ll sum_c=0;
    sort(a.begin(),a.end());
    for(int i=0;i<N-1;i++)
    {
        cur_+=a[i];
        sum_c+=cur_;
    }
    
    cout<<sum_d-sum_a-sum_c;
}