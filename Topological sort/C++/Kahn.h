#ifndef KAHN
#define KAHN
#include<vector>
#include<queue>
bool kahn(int &n,std::vector<int>&res,std::vector<std::vector<int>>&edges)
{
    std::vector<std::vector<int>>adj(n+1);
    std::vector<int>indeg(n+1,0);
    for(auto&e:edges)
    {
        adj[e[0]].push_back(e[1]);
        indeg[e[1]]++;
    }
    std::queue<int>q;
    for(int i=0;i<=n;i++)if(indeg[i]==0)q.push(i);
    while(!q.empty())
    {
        // write code here
        int u =q.front();
        q.pop();
        res.push_back(u);
        for(auto&v:adj[u])
        {
            indeg[v]--;
            if(indeg[v]==0)q.push(v);
        }
    }
    if(res.size()!=n+1)
    {
        return false;//cycle
    }
    return true;//no cycle
}
#endif