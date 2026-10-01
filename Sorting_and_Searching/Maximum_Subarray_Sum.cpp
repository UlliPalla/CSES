// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main() {
    // Write C++ code here
    int N;
    cin>>N;
    ll r,max_;
    cin>>r;
    max_=r;
    for(int i=1;i<N;i++)
    {
        ll k;
        cin>>k;
        max_=max(k,max_+k);
        r=max(r,max_);
    }
    cout<<r;
    return 0;
}