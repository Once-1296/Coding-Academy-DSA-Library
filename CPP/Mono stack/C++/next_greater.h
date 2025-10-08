#ifndef NEXT_GREATER
#define NEXT_GREATER
#include<vector>
#include<stack>
void nxt_g(std::vector<int>&v,std::vector<int>&next_g)
{
    next_g.resize(v.size());
    std::stack<int>st;
    for(int i=v.size()-1;i>=0;i--)
    {
        while(!st.empty()&&v[i]>=v[st.top()])
        {
            st.pop();
        }
        if(st.empty())next_g[i]=v.size();
        else next_g[i]=st.top();
        st.push(i);
    }
}
#endif