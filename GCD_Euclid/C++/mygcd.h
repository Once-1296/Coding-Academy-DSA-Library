#ifndef MYGCD
#define MYGCD
int mygcd(int a, int b)
{
    if(a==0||b==0)return 0;
    if(a==b)return a;
    if(a>b)return mygcd(a-b,b);
    return mygcd(a,b-a);
}
#endif