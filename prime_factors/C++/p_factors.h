#ifndef P_FACTORS
#define P_FACTORS
#include<vector>
#include<map>
void p_factors(int &n,std::map<int,int>&mp)
{
    int tmp =n;
   while(tmp%2==0)
   {
    tmp/=2;
    mp[2]++;
   } 
   for(int i =3;i*i<=tmp;i++)
   {
    while(tmp%i==0)
    {
        tmp/=i;
        mp[i]++;
    }
   }
   if(tmp>1)mp[n]=1;
}
#endif