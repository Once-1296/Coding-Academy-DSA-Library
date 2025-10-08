#ifndef BSRCTOMIN
#define BSRCTOMIN
#include<vector>
bool somecond(int &x)
{
    bool condition =1;
    //write condition code;
    return condition;
}
int binsrctomin(std::vector<int>&arr)
{
    int l =0,r=arr.size()-1;
    while(l<r)
    {
        int m = l+(r-l)/2;
        if(somecond(arr[m]))
        {
            r=m;
        }
        else
        {
            l=m+1;
        }
    }
    return r;
}
#endif