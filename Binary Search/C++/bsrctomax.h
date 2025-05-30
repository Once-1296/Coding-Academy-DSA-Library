#ifndef BSRCTOMAX
#define BSRCTOMAX
#include<vector>
bool somecond(int &x)
{
    bool condition =1;
    //write condition code;
    return condition;
}
int binsrctomax(std::vector<int>&arr)
{
    int l =0,r=arr.size()-1;
    while(l<r)
    {
        int m = l+(r-l+1)/2;
        if(somecond(arr[m]))
        {
            l=m;
        }
        else
        {
            r=m-1;
        }
    }
    return l;
}
#endif