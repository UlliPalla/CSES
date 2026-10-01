#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    // ifstream cin("input.txt");
    ll  N;
    cin>>N;
    vector<bool> v(N,true);
    for(int i=0;i<N;i++)
    {
        int k;
        cin>>k;
        v[k-1]=false;
    }
    for(int i=0;i<N;i++)
    {
        if(v[i])
        {
            cout<<i+1;
            break;
        }
    }
    return 0;
}