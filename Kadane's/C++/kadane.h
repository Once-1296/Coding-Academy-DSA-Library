#ifndef KADANE
#define KADANE
#include<vector>
int kadane(std::vector<int>&arr)
{
    int c_end=arr[0],res=arr[0];
    for(int i =1;i<arr.size();i++)
    {
        c_end=std::max(arr[i],c_end+arr[i]);
        res=std::max(res,c_end);
    }
    return res;
}
#endif