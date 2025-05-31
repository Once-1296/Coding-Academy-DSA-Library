#ifndef BT
#define BT
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
#endif