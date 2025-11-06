#ifndef LPS
#define LPS
#include<iostream>
#include<vector>
using namespace std;
//https://www.geeksforgeeks.org/print-longest-palindromic-subsequence/
string lcs(string &X, string &Y)
{
    int m = X.length();
    int n = Y.length();

    std::vector<std::vector<int>> L(m+1,std::vector<int>(n+1,0));

    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i-1] == Y[j-1])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    int index = L[m][n];

    string lcs(index+1, '\0');

    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (X[i-1] == Y[j-1])
        {
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        }

        else if (L[i-1][j] > L[i][j-1])
            i--;
        else
            j--;
    }

    return lcs;
}

string longestPalSubseq(string &str)
{

    string rev = str;
    reverse(rev.begin(), rev.end());
    return lcs(str, rev);
}
#endif