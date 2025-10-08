#ifndef KNAPSACK
#define KNAPSACK
#include<vector>
int knaps(int &lim, std::vector<std::pair<int,int>>&v)
{
    std:: vector<int> dp(lim+1,0);
    for(auto&e:v)
    {
        for(int i =lim;i>=e.first;i--)
        {
            dp[i]=std::max(dp[i],dp[i-e.first]+e.second);
        }
    }
    return dp[lim];
}
#endif