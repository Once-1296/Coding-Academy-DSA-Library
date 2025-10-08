#ifndef POST_I
#define POST_I
#include"BT.h"
#include<iostream>
#include<stack>
void post_i(Node *root)
{
    std::stack<Node*>s1,s2;
    s1.push(root);
    while(!s1.empty())
    {
        if(s1.top()==nullptr)
        {
            s1.pop();
            continue;
        }
        Node *tmp=s1.top();
        s2.push(tmp);
        s1.pop();
        s1.push(tmp->left);
        s1.push(tmp->right);
    }
    while(!s2.empty())
    {
        std::cout<<s2.top()->val<<"\n";
    }
}
#endif