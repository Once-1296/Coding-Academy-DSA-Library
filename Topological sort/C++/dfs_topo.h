#ifndef DFS_TOPO
#define DFS_TOPO
#include<vector>
#include<iostream>
#include<stack>
// Function to perform DFS and topological sorting
void topologicalSortUtil(int v, std::vector<std::vector<int>> &adj, std::vector<bool> &visited, std::stack<int> &st)
{

    // Mark the current node as visited
    visited[v] = true;

    // Recur for all adjacent vertices
    for (int i : adj[v])
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }

    // Push current vertex to stack which stores the result
    st.push(v);
}

std::vector<std::vector<int>> constructadj(int V, std::vector<std::vector<int>> &edges)
{

    std::vector<std::vector<int>> adj(V);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
    }

    return adj;
}

// Function to perform Topological Sort
std::vector<int> topologicalSort(int V, std::vector<std::vector<int>> &edges)
{

    // Stack to store the result
    std::stack<int> st;

    std::vector<bool> visited(V, false);
    std::vector<std::vector<int>> adj = constructadj(V, edges);
    // Call the recursive helper function to store
    // Topological Sort starting from all vertices one by
    // one
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            topologicalSortUtil(i, adj, visited, st);
    }

    std::vector<int> ans;

    // Append contents of stack
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    if(ans.size()!=V)
    {
        std::cout<<"Cycle in graph\n";
    }
    return ans;
}

#endif;