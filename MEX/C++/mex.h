#ifndef MEX
#define MEX
#include<vector>
int mex(std::vector<int>&arr)
{
    for(int i =0;i<arr.size();i++)
    {
        if(arr[i]<arr.size())
        {
            std::swap(arr[i],arr[arr[i]]);
        }
    }
    for(int i =0;i<arr.size();i++)
    {
        if(i!=arr[i])return i;
    }
    return (int)arr.size();
}
#endif