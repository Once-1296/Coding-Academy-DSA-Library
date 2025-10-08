#ifndef PREV_GREATER
#define PREV_GREATER
#include<vector>
#include<stack>
void prv_g(std::vector<int>&v,std::vector<int>&prev_g)
{
    prev_g.resize(v.size());
    std::stack<int>st;
    for(int i=0;i<v.size();i++)
    {
        while(!st.empty()&&v[i]>=v[st.top()])
        {
            st.pop();
        }
        if(st.empty())prev_g[i]=-1;
        else prev_g[i]=st.top();
        st.push(i);
    }
}
#endif