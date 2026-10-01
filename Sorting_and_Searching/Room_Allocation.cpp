#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    vector<array<ll,3>> v;
    for(int i=0;i<N;i++)
    {
        ll a,b;
        cin>>a>>b;
        v.push_back({a,1,i});
        v.push_back({b,-1,i});
    }
    ll cur_=0;
    sort(v.begin(),v.end(),[](const auto&a,const auto&b)
    {
        if(a[0]!=b[0])
        {
           return a[0]<b[0];  
        }
        else
        {
            return a[1]>b[1];
        }
        
    });
    map<ll,ll> mp;//suqlae perosan dove
    stack<ll> st;
    vector<ll> sol(N);
    for(int i=0;i<N;i++)
    {
        st.push(N-i);
    }
    ll max_=0;
    for(auto [d,t,idx]:v)
    {
        cur_+=t;
        if(t==1)
        {
            sol[idx]=st.top();
            mp[idx]=st.top();
            st.pop();
        }
        if(t==-1)
        {
            st.push(mp[idx]);
        }
        max_=max(max_,cur_);
        //cout<<d<<" "<<t<<"\n ";
 
    }
    cout<<max_<<" \n";
    for(int i=0;i<N;i++)
    {
        cout<<sol[i]<<" ";
    }
}