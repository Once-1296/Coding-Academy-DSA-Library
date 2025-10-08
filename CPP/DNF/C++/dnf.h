#ifndef DNF
#define DNF
//Dutch national flag
#include<vector>
void dnf(std::vector<int>&v)
{
    int l=0,m=0,r=v.size()-1;
    while(m<=r)
    {
        if(v[m]==0)
        {
            std::swap(v[l++],v[m++]);
        }
        else if(v[m]==2)
        {
            std::swap(v[m],v[r--]);
        }
        else m++;
    }
}
#endif