#ifndef F_S_PTR
#define F_S_PTR
#include<vector>
#include<queue>
class Node
{
    public:
    int val;
    Node *next;
    Node(int data=-1,Node*nxt=nullptr)
    {
        val=data;
        next=nxt;
    }
};
bool cycle(Node *head)
{
    Node*fast =head, *slow=head;
    while(fast&&fast->next)
    {
        fast =fast->next->next;
        slow=slow->next;
        if(fast==slow) return true;
    }
    return false;
}
#endif