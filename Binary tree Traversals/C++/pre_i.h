#ifndef PRE_I
#define PRE_I
#include"BT.h"
#include<iostream>
#include<stack>
void pre_i(Node *root)
{
    std::stack<Node*>st;
    st.push(root);
    while(!st.empty())
    {
        if(st.top()==nullptr)
        {
            st.pop();
            continue;
        }
        std::cout<<st.top()->val<<"\n";
        st.push(st.top()->right);
        st.push(st.top()->left);
        st.pop();
    }
}
#endif