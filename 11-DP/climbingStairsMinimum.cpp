//we are using memoization to store the minimum cost to reach each step same logic as climbing stairs as the right and left part of the tree repeat the same function calls
//use the separate vector named dp 
//store the first 2 steps cost in dp[0] and dp[1] as they are starting point 
// iterate from 2 to n as last step is also consider as a step cost 

//for each caculate the cost = cost[i] + min(dp[i-1],dp[i-2])
//return the minimum of last two steps as we can reach the top from either of them

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2 ;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }   

        return min(dp[n-1],dp[n-2]);

    }
};