#ifndef MOD_LIB
#define MOD_LIB
#include<vector>
typedef long long ll;
class mod_lib
{
    public:
    ll fact[600001];
    ll mod;
    mod_lib(ll &m)
    {
        mod=m;
        precompute();
    }
    ll add (ll a, ll b)
    {
        return ((a%mod)+(b%mod))%mod;
    }
    ll sub (ll a, ll b)
    {
        return ((((a%mod)-(b%mod))%mod) +mod)%mod;
    }
    ll mul (ll a, ll b)
    {
        return ((a%mod)-(b%mod))%mod;
    }
    ll powmod(ll x, ll n)
    {
        ll prod =1ll;
        while(n>0ll)
        {
            if(n&1)prod=mul(prod,x);
            x=mul(x,x);
            n>>=1;
        }
        return prod;
    }
    ll inv(ll x)
    {
        return powmod(x,mod-2ll);
    }
    void precompute()
    {
        fact[0]=1;
        fact[1]=1;
        for(ll i =2;i<=600000ll;i++)fact[i]=mul(fact[i-1],i);
    }
    ll nCk(ll n, ll k)
    {
        return mul(fact[n],mul(inv(fact[n-k]),inv(fact[k])));
    }
};
#endif