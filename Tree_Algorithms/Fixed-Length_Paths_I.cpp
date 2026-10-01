#include <bits/stdc++.h>
#define ll long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
using namespace std;
 
int centroid(int root,vector<int> &parent,vector<int> &head,vector<int> &to,vector<int> &nxt,vector<bool> &removed,vector<int> &sub)
{
    static vector<int> q;
    q.clear();
    q.push_back(root);
    parent[root]=-1;
    int h=0;
    while(h<(int)q.size())
    {
        int node=q[h++];
        sub[node]=1;
        for(int e=head[node];e!=-1;e=nxt[e])
        {
            int v=to[e];
            if(v!=parent[node] and !removed[v])
            {
                parent[v]=node;
                q.push_back(v);
            }
        }
    }
    int total=q.size();
    for(int i=total-1;i>=0;i--)
    {
        int node=q[i];
        int p=parent[node];
        if(p!=-1)
        {
            sub[p]+=sub[node];
        }
    }
    int cur_=root;
    int p_=-1;
    int half=total/2;
    while(true)
    {
        int heavy=-1;
        for(int e=head[cur_];e!=-1;e=nxt[e])
        {
            int v=to[e];
            if(v!=p_ and !removed[v] and sub[v]>half)
            {
                heavy=v;
                break;
            }
        }
        if(heavy==-1)
        {
            return cur_;
        }
        p_=cur_;
        cur_=heavy;
    }
}
 
int main()
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    int N,K;
    if(!(cin>>N>>K)) return 0;
    if(K>=N)
    {
        cout<<0;
        return 0;
    }
    vector<int> head(N,-1);
    vector<int> to((N-1)*2);
    vector<int> nxt((N-1)*2);
    int edge_idx=0;
    for(int i=0;i<N-1;i++)
    {
        int a,b;
        cin>>a>>b;
        a-=1;
        b-=1;
        to[edge_idx]=b;
        nxt[edge_idx]=head[a];
        head[a]=edge_idx++;
        to[edge_idx]=a;
        nxt[edge_idx]=head[b];
        head[b]=edge_idx++;
    }
    int root=0;
    vector<int> parent(N);
    vector<bool> removed(N,false);
    vector<int> sub(N,1);
    ll sol_=0;
    vector<int> cnt(K+1,0);
    cnt[0]=1;
    queue<int> q;
    q.push(root);
    vector<int> dist(N,0);
    vector<int> visit;
    visit.reserve(N);
 
    while(!q.empty())
    {
        int start=q.front();
        q.pop();
        cnt[0]=1;
        int C=centroid(start,parent,head,to,nxt,removed,sub);
        removed[C]=true;
        int max_depth=0;
        for(int e=head[C];e!=-1;e=nxt[e])
        {
            int v=to[e];
            if(removed[v])
            {
                continue;
            }
            visit.clear();
            dist[v]=1;
            parent[v]=C;
            visit.push_back(v);
            int h=0;
            while(h<(int)visit.size())
            {
                int node=visit[h++];
                if(dist[node]<=K)
                {
                    if(dist[node]>max_depth) max_depth=dist[node];
                }
                if(dist[node]>=K)
                {
                    continue;
                }
                for(int edge=head[node];edge!=-1;edge=nxt[edge])
                {
                    int nxt_node=to[edge];
                    if(nxt_node!=parent[node] and !removed[nxt_node])
                    {
                        dist[nxt_node]=dist[node]+1;
                        parent[nxt_node]=node;
                        visit.push_back(nxt_node);
                    }
                }
            }   
            for(int i=0;i<(int)visit.size();i++)
            {
                int d=dist[visit[i]];
                if(d<=K)
                {
                    sol_+=cnt[K-d];
                }
            }
            for(int i=0;i<(int)visit.size();i++)
            {   
                int d=dist[visit[i]];
                if(d<=K)
                {
                    cnt[d]+=1;
                }
            }
        }
        for(int i=0;i<=max_depth;i++)
        {
            cnt[i]=0;
        }
        for(int e=head[C];e!=-1;e=nxt[e])
        {
            int v=to[e];
            if(!removed[v])
            {
                q.push(v);
            }
        }   
    }
    cout<<sol_;
}