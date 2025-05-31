#ifndef IN_I
#define IN_I
#include"BT.h"
#include<iostream>
#include<stack>
void in_i(Node *root)
{
    std::stack<Node*>st;
    Node*curr=root;
    while(curr!=nullptr || !st.empty())
    {
        while(curr)
        {
            st.push(curr);
            curr=curr->left;
        }
        std::cout<<st.top()->val<<"\n";
        curr=st.top()->right;
        st.pop();
    }
}
#endif