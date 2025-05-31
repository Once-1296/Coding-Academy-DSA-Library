#ifndef DSU
#define DSU
#include<vector>
class dsu
{
    public:
    std::vector<int>par,rank;
    int sz;
    dsu(int &n)
    {
        par.resize(n+1);
        rank.resize(n+1,1);
        for(int i =0;i<=n;i++)par[i]=i;
    }
    int find(int u)
    {
        if(u!=par[u])return par[u]=find(par[u]);
        return u;
    }
    void comb(int u, int v)
    {
        int ru = find(u),rv=find(v);
        if(ru!=rv)
        {
            if(rank[ru]>=rank[rv])
            {
                par[rv]=ru;
                rank[ru]+=rank[rv];
            }
            else
            {
                par[ru]=rv;
                rank[rv]+=rank[ru];
            }
        }
    }
};
#endif