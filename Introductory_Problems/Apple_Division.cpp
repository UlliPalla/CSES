#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    //ifstream cin("input.txt");
    int T;
    T=1;
    for(int t=0;t<T;t++)
    {                                       
        int N;
        cin>>N;
        vector<ll> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        ll sol=LONG_LONG_MAX;   
        for(int b=0;b<(1<<(N));b++)
        {   
            ll t_c=0;
            for(int i=0;i<N;i++)
            {
                if(b&(1<<i))
                {
                    t_c+=A[i];
                }
                else
                {
                    t_c-=A[i];
                }
            }
            
            sol=min(sol,abs(t_c));
        }
        cout<<sol;
    }
}