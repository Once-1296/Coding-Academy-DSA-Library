#ifndef DINIC_H
#define DINIC_H
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Edge {
    int to, rev;
    long long cap, flow;
    Edge(int to, int rev, long long cap) : to(to), rev(rev), cap(cap), flow(0) {}
};
class Dinic {
    int n;
    vector<vector<Edge>> adj;
    vector<int> level, ptr;
public:
    Dinic(int n) : n(n), adj(n), level(n), ptr(n) {}
    void addEdge(int u, int v, long long cap) {
        adj[u].emplace_back(v, adj[v].size(), cap);
        adj[v].emplace_back(u, adj[u].size() - 1, 0); // reverse edge
    }
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q; q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Edge &e : adj[u]) {
                if (level[e.to] < 0 && e.flow < e.cap) {
                    level[e.to] = level[u] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] >= 0;
    }
    long long dfs(int u, int t, long long flow) {
        if (u == t || flow == 0) return flow;
        for (int &i = ptr[u]; i < (int)adj[u].size(); i++) {
            Edge &e = adj[u][i];
            if (level[e.to] == level[u] + 1) {  
                long long pushed = dfs(e.to, t, min(flow, e.cap - e.flow));
                if (pushed > 0) {
                    e.flow += pushed;
                    adj[e.to][e.rev].flow -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }
    long long maxFlow(int s, int t) {
        long long totalFlow = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, t, LLONG_MAX)) {
                totalFlow += pushed;
            }
        }
        return totalFlow;
    }
};
#endif