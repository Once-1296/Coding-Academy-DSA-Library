#ifndef BST
#define BST
#include<iostream>
class Node
{
    public:
    int val;
    Node*left,*right;
    Node(int data=-1,Node*l=nullptr,Node*r=nullptr)
    {
        val=data;
        left =l;
        right =r;
    }
};
class bst
{
    public:
    Node*root;
    bst()
    {
        Node *default;
        root=default;
    }
    Node* find_min(Node *start)
    {
        Node *tmp=start;
        if(tmp==nullptr)
        {
            std::cout<<"Empty BST\n";
            return tmp;
        }
        while(tmp->left)tmp=tmp->left;
        return tmp;
    }
    Node* find_max(Node *start)
    {
        Node *tmp=start;
        if(tmp==nullptr)
        {
            std::cout<<"Empty BST\n";
            return tmp;
        }
        while(tmp->right)tmp=tmp->right;
        return tmp;
    }
    std::pair<Node*,bool> search(int &key)
    {
        Node *tmp =root;
        while(!tmp)
        {
            if(tmp->val==key)return {tmp,true};
            if(key<tmp->val)tmp=tmp->left;
            else tmp=tmp->right;
        }
        return {nullptr,false};
    }
    Node *del(Node *cur,int &key)
    {
        if(cur==nullptr)return cur;
        if (key<cur->val)cur->left = del(cur->left, key);
        else if(key>cur->val)cur->right=del(cur->right,key);
        else
        {
            if(cur->left==nullptr)
            {
                Node* tmp = cur->right;
                delete cur;
                return tmp;
            }
            else if (cur->right ==nullptr)
            {
                Node* tmp = cur->left;
                delete cur;
                return tmp;
            }
            else
            {
                Node *tmp=find_min(cur->right);
                cur->val = tmp->val;
                cur->right=del(cur->right,cur->val);
            }
        }
        return cur;
    }
    Node* insert(Node*cur,int &key)
    {
        if(cur==nullptr)return new Node(key);
        if(cur->val==key)return cur;
        if(key<cur->val)cur->left=insert(cur->left,key);
        else cur->right=insert(cur->right,key);
        return cur;
    }
    void in_call(int &key)
    {
        root=insert(root,key);
    }
    void del_call(int &key)
    {
        root=del(root,key);
    }
};
#endif