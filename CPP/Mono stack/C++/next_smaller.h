#ifndef NEXT_SMALLER
#define NEXT_SMALLER
#include<vector>
#include<stack>
void nxt_s(std::vector<int>&v,std::vector<int>&next_s)
{
    next_s.resize(v.size());
    std::stack<int>st;
    for(int i=v.size()-1;i>=0;i--)
    {
        while(!st.empty()&&v[i]<=v[st.top()])
        {
            st.pop();
        }
        if(st.empty())next_s[i]=v.size();
        else next_s[i]=st.top();
        st.push(i);
    }
}
#endif