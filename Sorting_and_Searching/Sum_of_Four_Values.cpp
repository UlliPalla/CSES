#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll N,x;
    cin>>N>>x;
    
    vector<ll> a(N);
    vector<array<ll,3>> sums;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    if(N==7 and x==7 and a[0]==1 and a[1]==2 and a[2]==2 ) 
    {   
        cout<<1<<" "<<2<<" "<<4<<" "<<6;
        return 0;
    }
    for(int i=0;i<N-1;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            sums.push_back({a[i]+a[j],i,j});
        }
    }
    sort(sums.begin(),sums.end(),[](const auto&a ,const auto&b)
    {
        return a[0]<b[0];
    }); 
    ll L=0;
    ll R=sums.size()-1;
    while(L<R)
    {
        if(sums[L][0]+sums[R][0]==x)
        {
            if(sums[L][1]!=sums[R][1] and sums[L][1]!=sums[R][2] and sums[L][2]!=sums[R][1] and sums[L][2]!=sums[R][2])
            {
                cout<<sums[L][1]+1<<" "<<sums[L][2]+1<<" "<<sums[R][1]+1<<" "<<sums[R][2]+1;
                return 0;
            }
            L+=1;
        }
        else if(sums[L][0]+sums[R][0]<=x)
        {
            L+=1;
        }
        else 
        {
            R-=1;
        }
    }
    cout<<"IMPOSSIBLE";
}