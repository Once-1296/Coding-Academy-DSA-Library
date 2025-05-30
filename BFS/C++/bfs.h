#ifndef BFS
#define BFS
#include<vector>
#include<queue>
void bfs(int &u,std::vector<std::vector<int>>&adj)
{
    std::queue<int>q;
    q.push(u);
    while(!q.empty())
    {
        // write code here
        for(auto&v:adj[u])
        {
            q.push(v);
        }
    }
}
#endif