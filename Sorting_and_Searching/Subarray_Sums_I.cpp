#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,x;
    cin>>N>>x;
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    ll L=0;
    ll R=0;
    ll cnt_=0;
    ll sum_=a[0];
 
    while(R<N)
    {
        if(sum_==x)
        {
            cnt_+=1;
            sum_-=a[L];
            L+=1;
        }   
        else if(sum_<x)
        {
            R+=1;
            sum_+=a[R];
        }
        else 
        {
            sum_-=a[L];
            L+=1;
        }
 
    }
    cout<<cnt_;
}