#ifndef PQ
#define PQ
#include<vector>
#include<queue>
int pq_ex(std::vector<int>&v)
{
    int some_var=0;
    std::priority_queue<int>pq;
    for(auto&e:v)
    {
        pq.push(e);
        some_var+=pq.top();
        // can perform other operations
        // guys if you get a good example for priority_queue do inform to change this
    }
}
#endif