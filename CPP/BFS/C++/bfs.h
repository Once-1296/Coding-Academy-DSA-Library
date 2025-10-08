#ifndef BFS
#define BFS
#include<vector>
#include<iostream>
#include<queue>
void bfs(int &n,int &s,std::vector<std::vector<int>>&adj)
{
    std::queue<int>q;
    q.push(s);
    std::vector<bool>vis(n,0);
    while(!q.empty())
    {
        // write code here
        int u = q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        std::cout<<u<<"\n";
        for(auto&v:adj[u])
        {
            if(!vis[v])q.push(v);
        }
    }
}
#endif