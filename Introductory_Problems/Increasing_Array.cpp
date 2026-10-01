#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    //ifstream cin("input.txt");
    ll  N;
    cin>>N;
    ll p=-LONG_LONG_MAX;
    ll c=0;
    for(int i=0;i<N;i++)
    {
        ll k;
        cin>>k;
        if(p>k)
        {
            c+=(p-k);
 
        }
        p=max(k,p);
        
    }
    cout<<c;
    return 0;
}