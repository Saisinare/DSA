//problem 
/*

    Given a m x n grid, find the number of unique paths from the top-left corner to the bottom-right corner.

*/

//solution
/*
    1. ways to reach the first coloumn and row is 1 
    2. for other cells ways to reach are dp[i-1][j] + dp[i][j-1]
    3. return dp[m-1][n-1]
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp (m,vector<int>(n,0));
        for(int i =0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(i==0 || j==0){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};