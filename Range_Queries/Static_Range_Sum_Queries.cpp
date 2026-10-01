#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N,Q;
    //ifstream cin("input.txt");
    cin>>N>>Q;
    vector<ll> a(N);
    vector<ll> p(N);
    ll cur_=0;
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
        cur_+=a[i];
        p[i]=cur_;
    }
    for(int i=0;i<Q;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        if(a==0)
        {
            cout<<p[b];
        }
        else
        {
             cout<<p[b]-p[a-1];
        }
        cout<<"\n";
    }
}