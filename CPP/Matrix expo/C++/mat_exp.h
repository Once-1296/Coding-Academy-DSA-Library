#ifndef MAT_EXP
#define MAT_EXP
#include<iostream>
#include<vector>
typedef long long ll;
class matrix
{
    public:
    std::vector<std::vector<ll>>mat;
    ll n,m;
    matrix(ll nn, ll mm, std::vector<std::vector<ll>>in)
    {
        n=nn;
        m=mm;
        mat.resize(n,std::vector<ll>(m));
        for(int i =0;i<n;i++)
        {
            for(int j =0;j<m;j++)
            {
                mat[i][j]=in[i][j];
            }
        }
    }
    friend matrix operator*(matrix &a,matrix&b)
    {
        ll na=a.n,ma=a.m;
        ll nb=b.n,mb=b.m;
        std::vector<std::vector<ll>>cm(na,std::vector<ll>(mb,0));
        matrix c(na,mb,cm);
        if(ma!=nb)
        {
            std::cout<<"Error in matmul\n";
            return c;
        }
        for(int i =0;i<na;i++)
        {
            for(int j = 0;j<mb;j++)
            {
                ll res=0;
                for(int k =0;k<nb;k++)
                {
                    res+=(a.mat[i][k]*b.mat[k][j]);
                }
                c.mat[i][j]=res;
            }
        }
        return c;
    }
};
matrix I(3,3,{{1,0,0},{0,1,0},{0,0,1}});;
matrix tribo(int n,matrix &s)
{
    matrix F(3,3,{{0,1,0},{0,0,1},{1,1,1}});
    matrix M=I;
    while(n>0)
    {
        if(n&1)M=M*F;
        F=F*F;
        n>>=1;
    }
    return M*s;
}
#endif