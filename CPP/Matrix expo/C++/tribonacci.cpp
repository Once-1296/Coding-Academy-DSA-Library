#include<iostream>
#include<vector>
#include"mat_exp.h"
int main()
{
    matrix trib(3,1,{{0},{1},{2}});
    matrix res = tribo(6,trib);
    std::cout<<res.mat[2][0];
}