#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll  N;
    cin>>N;
    cout<<N<<" "; 
    while(N!=1)
    {
        if(N%2==0)
        {
            cout<<N/2<<" ";
            N/=2;
        }
        else
        {
            cout<<3*N+1<<" ";
            N=3*N+1;
        }
    }
    return 0;
}