#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,T;
    cin>>N>>T;
    vector<ll> m(N);
    ll sum_=0;
    ll max_=0;
    for(int i=0;i<N;i++)
    {
        cin>>m[i];
        sum_+=m[i];
        max_=max(max_,m[i]);
    }
    ll L=max_;
    ll R=sum_;
    ll best_=0;
    while(L<=R)
    {
        ll M=(L+R)/2;
        ll cnt_=1;
        ll cur_=0;
    
        for(int i=-0;i<N;i++)
        {   
            if(cur_+m[i]>M)
            {
                cur_=m[i];
                cnt_+=1;
            }
            else
            {
                cur_+=m[i];
            }
        }
        if(cnt_<=T)
        {
            R=M-1;
            best_=M;
        }
        else
        {
            L=M+1;
        }
    }
    cout<<best_;
}