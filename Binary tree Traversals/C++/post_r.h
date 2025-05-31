#ifndef POST_R
#define POST_R
#include"BT.h"
#include<iostream>
void post_r(Node *root)
{
    if(!root)return;
    post_r(root->left);
    post_r(root->right);
    std::cout<<root->val<<"\n";
}
#endif