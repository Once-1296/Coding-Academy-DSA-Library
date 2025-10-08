#ifndef BINSEARCH
#define BINSEARCH
#include<vector>
bool binsrc( int &k, std::vector<int>&arr)
{
    int l =0,r=arr.size()-1;
    while(l<=r)
    {
        int m = l+(r-l)/2;
        if(arr[m]==k)
        {
            return true;
        }
        else if(arr[m]>k)
        {
            r=m-1;
        }
        else
        {
            l = m+1;
        }
    }
    return false;
}
#endif