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
        for(int b=0;b<(1<<N);b++)
        {
            int g=b^(b>>1);
            for(int i=N-1;i>=0;i--)
            {
                if(1&(g>>i))
                {
                    cout<<1;
                }
                else
                {
                    cout<<0;
                }
            }
            cout<<"\n";
        }
    }
}