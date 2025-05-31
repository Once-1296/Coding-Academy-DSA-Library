#ifndef FEN_TR
#define FEN_TR
#include <vector>
class fen_tree
{
public:
    std::vector<int> F;
    // GeeksforGeeks code
    // https://www.geeksforgeeks.org/fenwick-tree-for-competitive-programming/
    fen_tree(std::vector<int> &arr)
    {
        int n = arr.size();
        // Build the fenwick tree
        for(int i = 1; i <= n; i++)
        {
            add(i, arr[i]);
        }
    }
    // Method to calculate prefix sum till index idx
    int sum(int idx)
    {
        int runningSum = 0;
        // Summing up all the partial sums
        while (idx > 0)
        {
            runningSum += F[idx];
            int rightMostSetBit = (idx & (-idx));
            idx -= rightMostSetBit;
        }
        return runningSum;
    }

    // Method to update the array by adding X to index idx
    void add(int idx, int X)
    {
        while (idx < F.size())
        {
            F[idx] += X;
            int rightMostSetBit = (idx & (-idx));
            idx += rightMostSetBit;
        }
    }

    // Method to calculate range sum from index l to r
    int rangeQuery(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};
#endif