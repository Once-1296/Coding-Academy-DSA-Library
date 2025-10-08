#ifndef IN_R
#define IN_R
#include"BT.h"
#include<iostream>
void in_r(Node *root)
{
    if(!root)return;
    in_r(root->left);
    std::cout<<root->val<<"\n";
    in_r(root->right);
}
#endif