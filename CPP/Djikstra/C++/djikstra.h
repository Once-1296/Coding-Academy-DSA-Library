#ifndef DJIKSTRA
#define DJIKSTRA
#include<vector>
#include<queue>
void djikstra(int &n, std::vector<int>&dist,int &s,std::vector<std::vector<std::pair<int,int>>>&adj)
{
    std::priority_queue<std::pair<int,int>,std::vector<std::pair<int,int>>,std::greater<std::pair<int,int>>>q;
    q.push({0,s});
    dist.resize(n,1e9);
    dist[s]=0;
    while(!q.empty())
    {
        // write code here
        int u =q.top().second;
        q.pop();
        for(auto&v:adj[u])
        {
            if(dist[v.first]>dist[u]+v.second)
            {
                dist[v.first]=dist[u]+v.second;
                q.push({dist[v.first],v.first});
            }
        }
    }
}
#endif