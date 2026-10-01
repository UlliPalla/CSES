#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
bool is_Prime(ll N)
{
    if(N<2)
    {
        return false;
    }
    if(N==2 or N==3)
    {
        return true;
    }
    if(N%2==0 or N%3==0 )
    {
        return false;
    }
    for(ll i=5;i*i<=N;i+=6)
    {
        if(N%i==0 or(N%(i+2)==0))
        {
            return false;
        }
    }
    return true;
}
 
int main()
{
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {
        ll N;
        cin>>N;
        N+=1;
        if(N<=2)
        {
            cout<<2<<" \n";
            continue;
        }
 
        if(N%2==0)
        {
            N+=1;
        }
        
        while(!is_Prime(N))
        {
            N+=2;
        }
        cout<<N<<"\n";
    }
}