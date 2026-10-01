#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,x;
    cin>>N>>x;
 
    vector<array<ll,2>> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i][0];
        a[i][1]=i+1;
    }
    sort(a.begin(),a.end(),[](const auto&a ,const auto&b)
    {
        return a[0]<b[0];
    });
    ll L=0;
    ll R=N-1;
    while(L<R)
    {
        if(a[L][0]+a[R][0]==x)
        {
            cout<<a[L][1]<<" "<<a[R][1];
            return 0;
        }
        else if(a[L][0]+a[R][0]>=x)
        {
            R-=1;
        }
        else 
        {
            L+=1;
        }
    }
    cout<<"IMPOSSIBLE";
 
 
}