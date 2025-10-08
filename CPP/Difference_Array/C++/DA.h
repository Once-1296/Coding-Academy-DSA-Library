#ifndef DA
#define DA
#include<vector>
void update(std::vector<int> &d, int l, int r, int x)
{
    d[l] += x;
    d[r + 1] -= x;
}

void d_arr(std::vector<int>&arr)
{
     std::vector<int> diff(arr.size()+1,0);
     diff[0]=arr[0];
     for(int i =1;i<arr.size();i++)
     {
        diff[i]= arr[i]-arr[i-1];
     }
     // call update with offset value x
     arr[0]=diff[0];
     for(int i =1;i<arr.size();i++)
     {
        arr[i]= diff[i]+arr[i-1];
     }
}
#endif