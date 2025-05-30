#ifndef SL_WIND
#define SL_WIND
#include<vector>
bool somecond(int &x,int&y)
{
    bool condition =1;
    //write condition code;
    return condition;
}
void do_stuff(int &x)
{
    //update x
}
void sl_wind(std::vector<int>&arr)
{
    int l =0,r=0;
    int some_var=0;
    while(r<arr.size())
    {
        while(somecond(arr[l],arr[r]))
        {
            do_stuff(some_var);
            l++;
            // write more code here
        }
       r++;
    }
}
#endif