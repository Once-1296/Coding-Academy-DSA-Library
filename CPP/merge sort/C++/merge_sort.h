#ifndef MERGE_SORT
#define MERGE_SORT
#include<vector>
#include<stack>
void ms(std::vector<int>&v,int l, int r)
{
    if(l>=r)return;
    int m = l+(r-l)/2;
    ms(v,l,m);
    ms(v,m+1,r);
    std::vector<int> left(m-l+1),right(r-m);
    for(int i =l;i<=m;i++)
    {
        left[i-l]=v[i];
    }
    for(int i =m+1;i<=r;i++)
    {
        right[i-m-1]=v[i];
    }
    std::vector<int>up;
    int x = 0,y=0;
    while(x<left.size()&&y<right.size())
    {
        if(left[x]<right[y])
        {
            up.push_back(left[x]);
            x++;
        }
        else 
        {
            up.push_back(right[y]);
            y++;
        }
    }
    while(x<left.size())up.push_back(left[x]);
    while(y<right.size())up.push_back(right[y]);
    int z=0;
    for(int i =l;i<=r;i++)v[i]=up[z++];
}
void call_ms(std::vector<int>&v)
{
    ms(v,0,(int)v.size()-1);
}
#endif