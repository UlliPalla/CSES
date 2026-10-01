#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
int main() {
    //ifstream cin("input.txt");
   
    ll N, M;
    if (!(cin >> N >> M)) return 0;
 
    vector<vector<ll>> matrix(N, vector<ll>(M));
 
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row; 
        
        for (int j = 0; j < M; j++) {
            if (row[j] == '.') {
                matrix[i][j] = 1; 
            } else if (row[j] == '*') {
                matrix[i][j] = 0; 
            }
        }
    }
 
 
    vector<vector<ll>> X(N,vector<ll>(M));
 
    for(int i =0;i<N;i++)
    {   
        for(int j=0;j<M;j++)
        {
            if(matrix[i][j]==1)
            {
                if(i>0)
                {
                    X[i][j]=X[i-1][j]+1;
                }
                else
                {
                    X[i][j]=1;
                }
 
            }
            else
            {
                X[i][j]=0;
            }
        }
    
    }
 
 
    ll global_max=0;
    stack<ll> st;
    
    for(int y=0;y<N;y++)
    {   
        vector<ll> DX;
        vector<ll> SX;
                
 
         while(!st.empty())
        {
            st.pop();
        }
 
            for(int i=0;i<M;i++)
        {
            while(!st.empty() and X[y][st.top()-1]>=X[y][i])
            {
                st.pop();
            }
            if(st.empty())
            {
                SX.push_back(0);
            }
            else
            {
                SX.push_back(st.top());
            }
 
            st.push(i+1);
        }
 
 
        while(!st.empty())
        {
            st.pop();
        }
 
        
 
        for(int i=M-1;i>=0;i--)
        {
            while(!st.empty() and X[y][st.top()-1]>=X[y][i])
            {
                st.pop();
            }
            if(st.empty())
            {
                DX.push_back(M+1);
            }
            else
            {
                DX.push_back(st.top());
            }
 
            st.push(i+1);
        }
 
 
        reverse(DX.begin(),DX.end());
        
 
        ll max_area=0;
 
        for(int i=0;i<M;i++)
        {
            max_area=max(X[y][i]*(DX[i]-SX[i]-1),max_area);
        }
        global_max=max(global_max,max_area);
        
    }
    cout<<global_max<<"\n";
    return 0;
}