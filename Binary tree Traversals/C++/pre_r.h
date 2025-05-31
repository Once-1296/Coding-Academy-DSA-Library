#ifndef PRE_R
#define PRE_R
#include"BT.h"
#include<iostream>
void pre_r(Node *root)
{
    if(!root)return;
    std::cout<<root->val<<"\n";
    pre_r(root->left);
    pre_r(root->right);
}
#endif