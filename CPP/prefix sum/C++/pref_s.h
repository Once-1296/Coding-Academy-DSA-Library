#ifndef PREF_S
#define PREF_S
#include<vector>
void pref_s(std::vector<int>&v,std::vector<int>&pref)
{
    pref.resize(v.size()+1);
    pref[0]=0;
    for(int i=1;i<=v.size();i++)
    {
        pref[i]=pref[i-1]+v[i-1];
    }
}
#endif