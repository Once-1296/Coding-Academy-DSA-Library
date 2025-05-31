#ifndef PRIM
#define PRIM
// C++ Program to implement the
// Prim's Algorithm using Adjecency matrix
//https://www.geeksforgeeks.org/prims-algorithm-in-cpp/
#include<vector>
#include<iostream>
#include<queue>
// Function to construct and print the MST
int primMST(std::vector<std::vector<int>> graph) {
    int v = graph.size();
  
    // vector to store the parent of vertex
    std::vector<int> parent(v);

    // vector holds the weight/ cost of the MST
    std::vector<int> key(v);

    // vector to represent the set of
    // vertices included in MST
    std::vector<bool> vis(v);

    std::priority_queue<std::pair<int, int>, 
    std::vector<std::pair<int, int>>, 
    std::greater<std::pair<int, int>>> pq;
  
    // Initialize all key vector as INFINITE
    // and vis vector as false
    for (int i = 0; i < v; i++) {
        key[i] = INT_MAX;
        vis[i] = false;
    }

    // Always include the first vertex in MST.
    // Make key 0 so that this vertex is
    // picked as the first vertex.
    key[0] = 0;

    // First node is always the root of MST
    parent[0] = -1;

    // Push the source vertex to the min-heap
    pq.push({0, 0});

    while (!pq.empty()) {
        int node = pq.top().second;
        pq.pop();
        vis[node] = true;
        for (int i = 0; i < v; i++) {
          
            // If the vertex is not visited
            // and the edge weight of neighbouring
            // vertex is less than key value of
            // neighbouring vertex then update it.
            if (!vis[i] && graph[node][i] != 0
                && graph[node][i] < key[i]) {
                pq.push({graph[node][i], i});
                key[i] = graph[node][i];
                parent[i] = node;
            }
        }
    }
    int sum=0;
    // Print the edges and their
    // weights in the MST
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        std::cout << parent[i] << " - " << i 
          << " \t" << graph[i][parent[i]] << " \n";
          sum+=graph[i][parent[i]];
    }
    return sum;
}
#endif;