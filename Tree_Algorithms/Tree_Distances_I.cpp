#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
int main() {
    //ifstream cin("input.txt");
    // ofstream cout("output.txt");
 
    int N;
    cin >> N;
 
    vector<vector<int>> grafo(N);
    for (int i = 0; i <N-1; i++)
    {
        int a,b;
        cin >> a >> b;
        grafo[a-1].push_back(b-1);
        grafo[b-1].push_back(a-1);
    }
    queue<int> que;
    que.push(0);
    vector<int> dist(N,-1);
    dist[0]=0;
    int max_=0;
    int max_u=0;
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(auto v:grafo[node])
        {
            if(dist[v]==-1)
            {
                dist[v]=dist[node]+1;
                que.push(v);
                if(dist[v]>max_)
                {
                    max_=dist[v];
                    max_u=v;
                }
 
                
            }
        }
    }
    while(!que.empty())
    {
        que.pop();
    }
    que.push(max_u);
    vector<int> dist1(N,-1);
    int max_2=0;
    int max_v=0;
    dist1[max_u]=0;
    
 
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(auto v:grafo[node])
        {
            if(dist1[v]==-1)
            {
                dist1[v]=dist1[node]+1;
                que.push(v);
                if(dist1[v]>max_2)
                {
                    max_2=dist1[v];
                    max_v=v;
                    
                }
 
                
            }
        }
    }
    while(!que.empty())
    {
        que.pop();
    }
    que.push(max_v);
    vector<int> dist2(N,-1);
    dist2[max_v]=0;
 
    
 
    while(!que.empty())
    {
        int node=que.front();
        que.pop();
        for(auto v:grafo[node])
        {
            if(dist2[v]==-1)
            {
                dist2[v]=dist2[node]+1;
                que.push(v);
                
 
                
            }
        }
    }
    if(N==1)
    {
        cout<<0;
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            cout<<max(dist1[i],dist2[i])<<" ";
        }
    }
 
}