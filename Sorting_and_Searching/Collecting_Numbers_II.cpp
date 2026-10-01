#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{
    int N,M;
    cin>>N>>M;
    vector<ll> a(N);
    vector<ll> p(N+2);
    p[N+1]=N+1;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    ll sol=1;
    for(int i=1;i<N;i++)
    {   
        //cout<<p[i]<<" ";
        if(p[i]>p[i+1])
        {
            sol+=1;
        }
    }
    
    while (M>0)
    {
        int A,B;
        cin>>A>>B;
        A-=1;
        B-=1;
 
        M-=1;
        set<array<ll,2>> tu;
        ll x=a[A];
        ll y=a[B];
        if(x>1)
        {
            tu.insert({x-1,x});
        }
        if(x<N)
        {
            tu.insert({x,x+1});
        }
        if(y>1)
        {
            tu.insert({y-1,y});
        }
        if(y<N)
        {
            tu.insert({y,y+1});
        }
        for(auto [X,Y]:tu)
        {
            if(p[Y]<p[X])
            {
                sol-=1;
            }
        }
        swap(a[A],a[B]);
        p[x]=B;
        p[y]=A;
        for(auto [X,Y]:tu)
        {
            if(p[Y]<p[X])
            {
                sol+=1;
            }
        }
        cout<<sol<<"\n";
    }
    
}