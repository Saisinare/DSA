//brute force solution 
/*
    simple two condition for recusrion 
    if(buy){
        max(
            -prices[index] + f(index+1,false);
            0 + f(index+1,true);
        )
    }else{
        max(
            prices[index] + f(index+2,true);
            0 + f(index+1,false);
            )
    }
*/

//optimal solution
/*
    using memoization we can solve this 
    but for more optimized solution tabulation should be used 
    space optimization can happens here 
*/
class Solution {
public:
    int perform(int index, int buy,vector<int>& prices,int n,vector<vector<int>> &dp){

        if(index>=n) return 0; 
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            return dp[index][buy] = max(
                -prices[index] + perform(index+1,0,prices,n,dp),
                perform(index+1,1,prices,n,dp)
            );
        }
        return dp[index][buy] = max(
            prices[index] + perform(index+2,1,prices,n,dp),
            perform(index+1,0,prices,n,dp)
        );
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp (n,vector<int>(2,-1));
        return perform(0,true,prices,n,dp);
    }
};