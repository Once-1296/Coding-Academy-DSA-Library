#ifndef SPARSE_TABLE_H
#define SPARSE_TABLE_H
#include <vector>
#include <cmath>
using namespace std;
vector<vector<int>> st;
vector<int> logTable(100005);
for (int i = 2; i < logTable.size(); i++)
    logTable[i] = logTable[i / 2] + 1;

void buildSparseTable(const vector<int> &a) {
    int n = a.size();
    int maxLog = logTable[n] + 1;
    st.assign(n, vector<int>(maxLog));
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j < maxLog; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int querySparseTable(int L, int R) {
    int j = logTable[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}
#endif