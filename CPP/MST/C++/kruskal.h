#ifndef KRUSKAL
#define KRUSKAL
#include<vector>
#include<algorithm>
class dsu
{
    public:
    std::vector<int>par,rank,weight;
    int sz;
    dsu(int &n)
    {
        par.resize(n+1);
        rank.resize(n+1,1);
        weight.resize(n+1,0);
        for(int i =0;i<=n;i++)par[i]=i;
    }
    int find(int u)
    {
        if(u!=par[u])return par[u]=find(par[u]);
        return u;
    }
    void comb(int u, int v, int w)
    {
        int ru = find(u),rv=find(v);
        if(ru!=rv)
        {
            if(rank[ru]>=rank[rv])
            {
                par[rv]=ru;
                rank[ru]+=rank[rv];
                weight[ru]+=weight[rv]+w;
            }
            else
            {
                par[ru]=rv;
                rank[rv]+=rank[ru];
                weight[rv]+=weight[ru]+w;
            }
        }
    }
};
bool b(std::vector<int>&a,std::vector<int>&b)
{
    if(a[2]<b[2])return true;
    return false;
}
int kruskal(int &n, std::vector<std::vector<int>>&edges)
{
    dsu d(n);
    //edges[0]=u,edges[1]=v, edges[2]=weight;
    sort(edges.begin(),edges.end(),b);
    for(auto&e:edges)
    {
        d.comb(e[0],e[1],e[2]);
    }
    int sum=0;
    std::vector<bool>vis(n+1,0);
    for(int i =0;i<=n;i++)
    {
        int ri = d.find(i);
        if(vis[ri])continue;
        sum+=d.weight[ri];
        vis[ri]=1;
    }
    return sum;
}
#endif