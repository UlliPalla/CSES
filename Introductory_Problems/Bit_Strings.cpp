#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    int T;
    T=1;
    for(int t=0;t<T;t++)
    {                                       
        int N;
        cin>>N;
        ll MOD=1e9+7;
        ll sol=1;
        for(ll i=1;i<=N;i++)
        {
            sol=(sol*2)%MOD;
        }
        cout<<sol;
    }
}