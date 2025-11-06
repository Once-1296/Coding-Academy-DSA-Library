#ifndef LCS
#define LCS
#include <iostream>
#include <vector>
using namespace std;
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/s
int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int index = dp[m][n];

    std::vector<char>lcs(index + 1);
    lcs[index] = '\0'; 
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1]
                = s1[i - 1]; 
            i--;
            j--;
            index--; 
        }

        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    std::string ans(lcs.begin(),lcs.end());

    cout << "LCS of " << s1 << " and " << s2<< " is " << ans;

    return dp[m][n];
}

#endif