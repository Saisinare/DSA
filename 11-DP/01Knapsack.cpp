//Problem
/*
    Given n items, each with a weight and a value,
    and a knapsack with capacity W,
    find the maximum total value you can put in the knapsack
    such that the total weight does not exceed W.
    Each item can be included at most once (0/1).
*/

//Brute Force (Recursion)
/*
    For each item, we have two choices:
        1. Include it (if weight allows)
        2. Exclude it
    Recurse over all items and return the maximum value.
    T.C: O(2^n)  S.C: O(n) recursion stack
*/
// int solve(vector<int>& wt, vector<int>& val, int W, int n) {
//     if (n == 0 || W == 0) return 0;
//     if (wt[n-1] > W)
//         return solve(wt, val, W, n-1);
//     int incl = val[n-1] + solve(wt, val, W - wt[n-1], n-1);
//     int excl = solve(wt, val, W, n-1);
//     return max(incl, excl);
// }

//Memoization (Top-Down DP)
/*
    Cache results of overlapping subproblems using dp[n][W].
    T.C: O(n * W)  S.C: O(n * W)
*/
// int solve(vector<int>& wt, vector<int>& val, int W, int n, vector<vector<int>>& dp) {
//     if (n == 0 || W == 0) return 0;
//     if (dp[n][W] != -1) return dp[n][W];
//     if (wt[n-1] > W)
//         return dp[n][W] = solve(wt, val, W, n-1, dp);
//     int incl = val[n-1] + solve(wt, val, W - wt[n-1], n-1, dp);
//     int excl = solve(wt, val, W, n-1, dp);
//     return dp[n][W] = max(incl, excl);
// }

//Tabulation (Bottom-Up DP)
/*
    Build a 2D dp table where dp[i][w] = max value using first i items with capacity w.
    T.C: O(n * W)  S.C: O(n * W)
*/
#include <bits/stdc++.h>
using namespace std;

int knapsack(vector<int>& wt, vector<int>& val, int W, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // exclude current item
            dp[i][w] = dp[i-1][w];
            // include current item if it fits
            if (wt[i-1] <= w)
                dp[i][w] = max(dp[i][w], val[i-1] + dp[i-1][w - wt[i-1]]);
        }
    }
    return dp[n][W];
}

//Space Optimized (1D DP)
/*
    We only need the previous row, so use a single 1D dp array.
    Traverse w from right to left to avoid using an item more than once.
    T.C: O(n * W)  S.C: O(W)
*/
int knapsackOptimized(vector<int>& wt, vector<int>& val, int W, int n) {
    vector<int> dp(W + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
        }
    }
    return dp[W];
}

int main() {
    int n, W;
    cout << "Enter number of items and knapsack capacity: ";
    cin >> n >> W;

    vector<int> wt(n), val(n);
    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Enter values: ";
    for (int i = 0; i < n; i++) cin >> val[i];

    cout << "Max value (tabulation): " << knapsack(wt, val, W, n) << endl;
    cout << "Max value (space optimized): " << knapsackOptimized(wt, val, W, n) << endl;

    return 0;
}
