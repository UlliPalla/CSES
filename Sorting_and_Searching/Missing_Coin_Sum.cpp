#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        
    }
    sort(a.begin(),a.end());
    ll cur_=1;
    for(int i=0;i<N;i++)
    {
        if(cur_<a[i])
        {
            
            break;
 
        }
        else 
        {
            cur_+=a[i];
        }
    }
    cout<<cur_;
   
}