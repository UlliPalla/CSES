#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main()
{   
    //ifstream cin("input.txt");
    int T;
    cin>>T;
    for(int t=0;t<T;t++)
    {                                       
        ll x,y;
        cin>>y>>x;
        if(x==y)
        {
            cout<<x*x-x+1;
        }
        else if(x>y)
        {
            if(x%2==1)
            {
                cout<<x*x-y+1;
            }
            else
            {
                cout<<(x-1)*(x-1)+y;
            }
        }
        else
        {
            if(y%2==0)
            {
                cout<<y*y-x+1;
            }
            else
            {
                cout<<(y-1)*(y-1)+x;
            }
        }
        cout<<"\n";
    }
}