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
        for(ll i=1;i<=N;i++)
        {
            cout<<(i*i)*(i*i-1)/2 -4*(i-1)*(i-2)<<"\n";
        }
    }
}