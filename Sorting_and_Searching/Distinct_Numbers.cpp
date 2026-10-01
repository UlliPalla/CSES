#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    ll sol=0;
    vector<bool> v(1e9+1,false);
    for(int i=0;i<N;i++)
    {   
        ll k;
        cin>>k;
        if(v[k])
        {
            continue;
        }
        else 
        {
            v[k]=true;
            sol+=1;
        }
 
    }
    cout<<sol;
}