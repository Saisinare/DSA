//brute force : recursion 
/*
    cases: 
        1. can buy : 
            1) bought and cannot buy tommarow 
            2) not bought and can buy tommarow 
        2. can sell 
            1) sold and can buy tommarow (subtract the transaction fees)
            2) not soled and cannot buy tommarow  
*/  
/*
class Solution {
public:
    int solve(vector<int>& prices,int buy, int fee, int index, int n){
        if(index >= n) return 0 ;
        int profit = 0 ;
        if(buy){
            profit = max(
                -prices[index] + solve(prices,0,fee,index+1,n),
                solve(prices,1,fee,index+1,n)  
            );
        }else{
            profit = max(
                prices[index] - fee + solve(prices,1,fee,index+1,n),
                solve(prices,0,fee,index+1,n)
            );
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return solve(prices,1,fee,0,n);
    }
};
*/

//better : memoization 
/*
class Solution {
public:
    int solve(vector<int>& prices,int buy, int fee, int index, int n,vector<vector<int>>& dp){
        if(index >= n) return 0 ;
        int profit = 0 ;
        if(dp[index][buy]!=-1) return dp[index][buy];
        if(buy){
            profit = max(
                -prices[index] + solve(prices,0,fee,index+1,n,dp),
                solve(prices,1,fee,index+1,n,dp)  
            );
        }else{
            profit = max(
                prices[index] - fee + solve(prices,1,fee,index+1,n,dp),
                solve(prices,0,fee,index+1,n,dp)
            );
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp (n,vector<int>(2,-1));
        return solve(prices,1,fee,0,n,dp);
    }
};
*/
//optimal : tabulation 
/*
    base cases: when index == n return 0 
*/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp (n+1,vector<int>(2,-1));
        //base case 
        for(int buy= 0 ;buy<2;buy++){
            dp[n][buy] = 0;  
        }

        for(int index = n -1 ;index>=0;index--){
            for(int buy = 0 ; buy <2 ; buy++){
                if(buy){
                    dp[index][buy] = max(
                    -prices[index] + dp[index+1][0],
                    dp[index+1][1]  
                    );
                }else{
                    dp[index][buy] = max(
                    prices[index] - fee + dp[index+1][1],
                    dp[index+1][0]
                    );
                }
            }
        }
        return dp[0][1];
    }
};
*/
//most optimal : tabulation with 1 dp maybe 
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> cur (2,0);
        vector<int> ahead (2,0);

        for(int index = n -1 ;index>=0;index--){
            for(int buy = 0 ; buy <2 ; buy++){
                if(buy){
                    cur[buy] = max(
                    -prices[index] + ahead[0],
                    ahead[1]  
                    );
                }else{
                    cur[buy] = max(
                    prices[index] - fee + ahead[1],
                    ahead[0]
                    );
                }
            }
            ahead = cur;
        }
        return ahead[1];
    }
};