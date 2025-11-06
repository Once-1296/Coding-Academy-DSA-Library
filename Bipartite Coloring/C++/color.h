#ifndef COLOR_H
#define COLOR_H
bool isBipartiteUtil(const vector<vector<int>> &adj, vector<int> &color, int s, int currColor) {
    color[s] = currColor;
    for (int v : adj[s]) {
        if (color[v] == -1) {
            if (!isBipartiteUtil(adj, color, neighbor, 1 - currColor))
                return false;
        } else if (color[neighbor] == currColor) {
            return false;
        }
    }
    return true;
}
#endif