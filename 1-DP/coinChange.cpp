//first approach will be the greedy approach in which: 
/*
    1. find the most closest bigger value to the amount 
    2. reduce it from the amount increase the coin count and repeat 

    //limitation:
        1. fails -> where test case like [1,5,6,9] amount = 11
        --> select 9 first and coins required  for it will be 3 ->[9,1,1]
        But, real answer is 2 coins ( 6 + 5 ) missed by greedy 
*/

//thats why we are using recursion and backtracking 
    /*
        In this approach most of the decision trees most of the decisions are repated so we needed the DP solution 
    */

//So here is the DP solution: 
    /*
        1. Create an array dp[0...amount]

        2. dp[i] = minimum coins needed to make amount i
        Fill with INT_MAX (meaning: not possible yet)

        Base case:
            dp[0] = 0 → 0 coins needed to make amount 0
            For each amount i from 1 → amount:

        Try using every coin

        If coin fits (coin <= i) and the smaller amount (i - coin) is possible,
        The update: 
        dp[i] = min(dp[i], 1 + dp[i - coin])

        At the end:
            If dp[amount] == INT_MAX → not possible → return -1
            Else → return dp[amount] (minimum coins)
    */
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX);
        dp[0] = 0;
        for(int i =1;i<=amount;i++){
            for(int coin:coins){
              if(coin<=i && dp[i-coin]!=INT_MAX)
                dp[i] = min(dp[i],dp[i-coin]+1);
            }
        }
        if(dp[amount]==INT_MAX) return -1;
        return dp[amount];
    }
};