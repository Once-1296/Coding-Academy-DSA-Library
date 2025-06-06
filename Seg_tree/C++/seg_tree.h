#ifndef SEG_TREE
#define SEG_TREE
#include<vector>
#include<cmath>
class seg_tree
{
    public:
    std::vector<int>st;
    int sz;
    seg_tree(std::vector<int>&v)
    {
        int n = v.size();
        st.resize(4*n,0);
        sz=pow(2,ceil(log2(n)));
        int x=0;
        for(int i =sz;i<sz+n;i++)
        {
            st[i]=v[x++];
        }
        for(int i =sz+n;i<2*sz;i++)
        {
            st[i]=0;//sum
            //st[i]=INT_MIN //max tree
            //st[i]=INT_MAX //min tree
        }
        for(int i =sz-1;i>0;i--)
        {
            st[i] = st[(i<<1)]+st[(i<<1)|1];
            // st[i] = std::min(st[(i<<1)],st[(i<<1)|1])
            // st[i] = std::max(st[(i<<1)],st[(i<<1)|1])
        }
    }
    void up(int &ind,int &x)
    {
        st[ind+sz]=x;
        int pos=(ind+sz)>>1;
        while(pos>0)
        {
             st[pos] = st[(pos<<1)]+st[(pos<<1)|1];
            // st[pos] = std::min(st[(pos<<1)],st[(pos<<1)|1])
            // st[pos] = std::max(st[(pos<<1)],st[(pos<<1)|1])
            pos>>=1;
        }
    }
    int query(int ind, int low, int high, int l, int r)
{
    if (l > high || r < low || low > high)
      {
        return 0;//sum
        return INT_MIN; // max tree
        return INT_MAX;// min _tree
      }
    if (l <= low && high <= r)
       return st[ind];
    int mid = (low+high) / 2;
    int p1 = query((ind<<1),low,mid,l,r);
    int p2 = query((ind<<1)|1,mid+1,high,l,r);
    return p1+p2;
    return std::min(p1,p2);// min tree
    return std::max(p1,p2);// max tree
}
int qry(int &l,int &r)
{
    return query(1, 0,sz-1,l,r);
}
};
#endif
