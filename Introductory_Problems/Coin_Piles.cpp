#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {                                       
        int N,M;
        cin>>N>>M;
 
        if(2*min(N,M)<max(N,M) or (N+M)%3!=0)
        {
            cout<<"NO\n";
        }
        else
        {
            cout<<"YES\n";
        }
 
 
        
    }
}