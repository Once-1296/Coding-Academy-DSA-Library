#ifndef LCS
#define LCS
#include <iostream>
#include <vector>
using namespace std;
//https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/s
// Returns length of LCS for s1[0..m-1], s2[0..n-1]
//https://www.geeksforgeeks.org/printing-longest-common-subsequence/
int lcs(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int index = dp[m][n];

    // Create a character array to store the lcs string
    std::vector<char>lcs(index + 1);
    lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    int i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (s1[i - 1] == s2[j - 1]) {
            lcs[index - 1]
                = s1[i - 1]; // Put current character in result
            i--;
            j--;
            index--; // reduce values of i, j and index
        }

        // If not same, then find the larger of two and
        // go in the direction of larger value
        else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }
    std::string ans(lcs.begin(),lcs.end());
    // Print the lcs
    cout << "LCS of " << s1 << " and " << s2<< " is " << ans;
    // dp[m][n] contains length of LCS for s1[0..m-1]
    // and s2[0..n-1]
    return dp[m][n];
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    cout << lcs(s1, s2) << endl;

    return 0;
}
#endif