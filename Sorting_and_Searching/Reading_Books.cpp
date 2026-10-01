#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    ll sol_=0;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        sol_+=a[i];
    }
    ll max_=sol_;
    for(int i=0;i<N;i++)
    {
        if(2*a[i]>sol_)
        {
            max_=max(max_,2*a[i]);
        }
    }
   
    
    cout<<max_;
}