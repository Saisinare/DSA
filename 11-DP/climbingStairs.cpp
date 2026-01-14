// Recursion tree for n=4:
//
//                   climb(4)
//                 /         \
//           climb(3)         climb(2)
//           /     \          /     \
//     climb(2)  climb(1)  climb(1)  climb(0)
//     /     \
//  climb(1) climb(0)
//
// As you can see, the left and the right part of the tree repeat the same function calls.
// To avoid recomputation, we store the results of subproblems (memoization).
//
// Using DP (bottom-up), we only need the last two results at any time, 
// so space complexity can be reduced to O(1).
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Initialization:
// - climb(0) = 1 (1 way: do nothing, already at floor 0)
// - climb(1) = 1 (1 way: single step)
// These correspond to the two variables we keep.
//
// Then we iterate from 2 to n and update the variables:
// ways[i] = ways[i-1] + ways[i-2]


//you can reach n by only 2 paths 
//1. from n-1 or n-2 so their is no other path 
// and if n == 0 or n ==1 then their is only one path to reach it 
/*
class Solution {
public:
    int solve(int n,vector<int>& dp){
        //base case 
        if(n==0 || n==1) return 1;
        
        if(dp[n]!=-1) return dp[n];

        return dp[n] = solve(n-1,dp) + solve(n-2,dp);

    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};
*/
//memoization
// class Solution {
// public:
//     int climbStairs(int n) {
//         vector<int> dp(n+1,1);
//         if(n<=1) return 1;
//         for(int i = 2 ;i<= n ;i++){
//             dp[i] = dp[i-1] + dp[i-2];
//         }
//         return dp[n];
//     }
// };
//as our answer is just dependent on past 2 variables we just need that 
class Solution {
public:
    int climbStairs(int n) {
        int n1 = 1, n2 =1;
        if(n<=1) return 1;
        for(int i = 2 ;i<= n ;i++){
            int sum  = n1 + n2;
            n1 = n2;
            n2 = sum;
        }
        return n2;
    }
};
