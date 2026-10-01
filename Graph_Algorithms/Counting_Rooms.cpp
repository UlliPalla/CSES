#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
 
int main()
{   
    //ifstream cin("input.txt");
    ll N,M;
    cin>>N>>M;
 
 
    vector<vector<int>> X(N+2,vector<int> (M+2,0));
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=M;j++)
        {
            char x;
            cin>>x;
            if(x=='.')
            {
                X[i][j]=1;
            }
        }
    }
    ll sol_=0;
    vector<vector<ll>> color(N+1,vector<ll> (M+1,-1));
    stack<array<ll,2>>st;
    vector<vector<bool>> visto(N+2,vector<bool> (M+2,false));
    for(int i=1;i<=N;i++)
    {   
       
        for(int j=1;j<=M;j++)
        {   
            if(X[i][j]==1)
            {
                if(!visto[i][j] and X[i][j]==1)
                {
                    sol_+=1;
                    st.push({i,j});
                    while(!st.empty())
                    {
                        array<ll,2> co=st.top();
                        st.pop();
                        if(!visto[co[0]][co[1]])
                        {
                            visto[co[0]][co[1]]=true;
                            vector<array<ll,2>> d={{1,0},{-1,0},{0,1},{0,-1}};
                            for(auto [x,y]:d)
                            {
                                if(!visto[co[0]+x][co[1]+y] and X[co[0]+x][co[1]+y]==1)
                                {
                                    st.push({co[0]+x,co[1]+y});
                                }
                            }
                        }
                    } 
                }
            }         
           
        }
    }
    cout<<sol_;
    
    
   
 
}