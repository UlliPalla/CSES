#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{
    int N;
    cin>>N;
    if(N==2 or N==3)
    {
        cout<< "NO SOLUTION";
        
    }
    else
    {
        for(int i=2;i<=N;i+=2)
        {
            cout<<i<<" ";
        }
        for(int i=1;i<=N;i+=2)
        {
            cout<<i<<" ";
        }
    }
}