//brute force solution 
    /*
        Try every combination 
        Time Consuming 
    */

//Optimal Solution :Use DP
    /*    
        1. maintain the dp[sum] = no_of_ways
        2. start with dp[0] = 1
        3. traverse through array 
        4. for every element their are two choices either + or - 
        5. store the respective no_of_ways to the element 
        6. return dp[target]
    */
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        map<int,int> dp;
        dp[0] = 1;

        for(int num : nums){
            map<int,int> nextDp;
            for(auto [sum,count] : dp){
                nextDp[sum-num] += count;
                nextDp[sum+num] += count;
            }
            dp = nextDp;
        }
        return dp[target];
    }
};