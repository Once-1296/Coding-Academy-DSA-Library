#ifndef DFS
#define DFS
#include<vector>
void dfs(int &u,std::vector<std::vector<int>>&adj)
{
    //write code here in tail recursion
    for(auto&v:adj[u])
    {
        dfs(v,adj);
    }
    //write code here in head recursion
}
#endif