#ifndef ERA_SIEVE
#define ERA_SIEVE
#include<vector>
void era_sieve(int &n,std::vector<int>&primes)
{
    std::vector<bool>p(n+1,1);
    p[0]=0;
    p[1]=1;
    for(int i =2;i*i<=n;i++)
    {
        if(!p[i])continue;
        int j = 2*i;
        for(;j<=n;j+=i)
        {
            p[j]=0;
        }
    }
    for(int i =0;i<=n;i++)
    {
        if(p[i])primes.push_back(i);
    }
}
#endif