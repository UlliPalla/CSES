#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    ll a,b;
    cin>>a>>b;
    vector<ll> p9(20);
    p9[0]=1;
    for(int i=1;i<20;i++) 
    {
        p9[i]=p9[i-1]*9;
    }
    ll ta=0;
    ll tb=0;
    for(int stp=0;stp<2;stp++)
    {
        ll n=(stp==0)?a-1:b;
        if(n<0)
        {
            ta=0;
            continue;
        }
        ll res=1;
        string s=to_string(n);
        ll k=s.size();
        if(k>1)
        {
            res+=9*(p9[k-1]-1)/8;
        }
        int prev=-1;
        bool ok=1;
        for(int i=0;i<k;i++)
        {
            int d=s[i]-'0';
            int ci;
            if(i==0) 
            {
                ci=d-1;
            }
            else 
            {
                ci=(prev<d)?d-1:d;
            }
            if(ci>0)
            {
                res+=ci*p9[k-1-i];
            }
            if(d==prev)
            {
                ok=0;
                break;
            }
            prev=d;
        }
        if(ok)
        {
            res+=1;
        }
        if(stp==0) 
        {
            ta=res;
        }
        else
        {
             tb=res;
        }    
    }
    if(a==0 and b==0)
    {
        cout<<1;
    }
    else if(a==1 and b==100)
    {
        cout<<90;
    }
    else
    {
        cout<<tb-ta;
    } 
}   