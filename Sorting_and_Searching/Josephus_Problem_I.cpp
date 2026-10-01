#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    bool gd=false;
    queue<ll> q;
    for(int i=1;i<=N;i++)
    {
        q.push(i);
    }
    while(!q.empty())
    {
        ll p =q.front();
        q.pop();
        if(gd)
        {
            cout<<p<<" ";
        }
        else
        {
            q.push(p);
        }
        gd=!gd;
    }
}