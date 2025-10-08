#ifndef PREV_SMALLER
#define PREV_SMALLER
#include<vector>
#include<stack>
void prv_s(std::vector<int>&v,std::vector<int>&prev_s)
{
    prev_s.resize(v.size());
    std::stack<int>st;
    for(int i=0;i<v.size();i++)
    {
        while(!st.empty()&&v[i]<=v[st.top()])
        {
            st.pop();
        }
        if(st.empty())prev_s[i]=-1;
        else prev_s[i]=st.top();
        st.push(i);
    }
}
#endif