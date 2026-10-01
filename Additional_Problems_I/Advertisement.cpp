#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    
    //ifstream cin("input.txt");
    int N;
    if (!(cin >> N)) return 0;
 
    vector<long long> x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
 
 
    stack<long long> st;
 
    vector<long long> SX;
 
    for(int i=0;i<N;i++)
    {
        while(!st.empty() and x[st.top()-1]>=x[i])
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
 
    vector<long long> DX;
 
    for(int i=N-1;i>=0;i--)
    {
        while(!st.empty() and x[st.top()-1]>=x[i])
        {
            st.pop();
        }
        if(st.empty())
        {
            DX.push_back(N+1);
        }
        else
        {
            DX.push_back(st.top());
        }
 
        st.push(i+1);
    }
 
 
    reverse(DX.begin(),DX.end());
    /*
    for(int i=0;i<N;i++)
    {
        cout<<SX[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<N;i++)
    {
        cout<<DX[i]<<" ";
    }
    cout<<"\n";
    */
    long long max_area=N;
 
    for(int i=0;i<N;i++)
    {
        max_area=max(x[i]*(DX[i]-SX[i]-1),max_area);
    }
 
    cout<<max_area<<"\n";
    
    return 0;
}