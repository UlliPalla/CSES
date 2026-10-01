#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<ll> a(N);
    for(int i=0;i<N;i++)
    {
        cin>>a[i];
    }
    set<ll> s;
    ll L=0;
    ll R=0;
    ll max_=0;
    ll cur_=0;
    while(R<N)
    {
        if(!s.count(a[R]))
        {   
            s.insert(a[R]);
            max_=max(max_,cur_+1);
            cur_+=1;
            //cout<<"inserisco"<<a[R]<<"\n";
        }
        else
        {   
 
            bool gd=false;
            while(!gd)
            {
                if(a[L]==a[R])
                {
                    gd=true;
                    L+=1;
                    //cout<<"tolgo"<<a[L-1]<<"\n";
                }
                else 
                {   
                    s.erase(s.find(a[L]));
                    L+=1;
                    cur_-=1;
                    //out<<"tolgo"<<a[L-1]<<"\n";
                    
                }
            }
 
        }
        R+=1;
    }
    cout<<max_;
}