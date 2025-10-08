#ifndef TWO_PNTRS
#define TWO_PNTRS
#include<vector>
bool somecond(int &x,int&y)
{
    bool condition =1;
    //write condition code;
    return condition;
}
void two_pntrs(std::vector<int>&arr)
{
    int l =0,r=arr.size()-1;
    while(l<r)
    {
        if(somecond(arr[l],arr[r]))
        {
            l++;
            // write more code here
        }
        else 
        {
            r++;
        }
    }
}
#endif