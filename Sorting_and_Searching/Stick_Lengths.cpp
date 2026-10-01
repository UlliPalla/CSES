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
    
   ll med=0;
   if(N%2==1)
   {
        med=a[N/2];
   }
   
   med=a[N/2];
    ll sum_=0;
    for(int i=0;i<N;i++)
    {
        sum_+=abs(a[i]-med);
    }
    cout<<sum_;
}