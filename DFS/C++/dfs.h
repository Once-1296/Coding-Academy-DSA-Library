#ifndef DFS
#define DFS
#include<vector>
#include<iostream>
void dfs(int &u,std::vector<std::vector<int>>&adj,std::vector<bool>&vis)
{
    //write code here in tail recursion
    if(vis[u])return;
    vis[u]=1;
    std::cout<<u<<"\n";
    for(auto&v:adj[u])
    {
        if(!vis[v])dfs(v,adj,vis);
    }
    //write code here in head recursion
}
#endif