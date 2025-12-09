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
        //base case //Brute force: Recursion 
/*
class Solution {
public:
    int solve(int k, vector<int>& prices,int index,int n,int buy){
        if(k == 0 || index >= n) return 0;
        int profit = 0 ;
        if(buy){
            profit = max(
                        -prices[index] + solve(k,prices,index+1,n,0),
                        solve(k,prices,index+1,n,1)
                        );
        }else{
            profit = max(
                        prices[index] + solve(k-1,prices,index+1,n,1),
                        solve(k,prices,index+1,n,0)
            );
        }
        return profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        return solve(k,prices,0,prices.size(),1);
    }
};
*/
//Use memoization to bypass the TLE 
/*
class Solution {
public:
    int solve(int k, vector<int>& prices,int index,int n,int buy,vector<vector<vector<int>>>& dp){
        if(k == 0 || index >= n) return 0;
        int profit = 0 ;
        if(dp[index][buy][k]!=-1) return dp[index][buy][k]; 
        if(buy){
            profit = max(
                        -prices[index] + solve(k,prices,index+1,n,0,dp),
                        solve(k,prices,index+1,n,1,dp)
                        );
        }else{
            profit = max(
                        prices[index] + solve(k-1,prices,index+1,n,1,dp),
                        solve(k,prices,index+1,n,0,dp)
            );
        }
        return dp[index][buy][k] =  profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(k,prices,0,n,1,dp);
    }
};
*/
/*
    TC: O(N*k*2)
    SC: O(N*k*2) + O(N)
*/

//Use tabulation: to reduce the space complexity and remove the recursive stack space 
/*
    1. Find out the base case 
    2. Fill the predefined values 
    3. Fill out rest of the array 
*/
/*
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // base case: when index == 0 or count == k it will be 0; 
        for(int i = 0;i<2;i++){
            for(int j = 0;j<k;j++){
                dp[0][i][j] = 0;
            }
        }
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<2;buy++ ){
                for(int count = 1;count<=k;count++){
                        if(buy){
                            dp[index][buy][count] = max(
                                        -prices[index] + dp[index+1][0][count],
                                        dp[index+1][1][count]
                                        );
                        }else{
                            dp[index][buy][count] = max(
                                        prices[index] + dp[index+1][1][count-1],
                                        dp[index+1][0][count]
                            );
                        }
                }
            }
        }
        return dp[0][1][k];
    }
};
*/
/*
    TC : O(N*K*2)
    SC : O(N*K*2) 
*/

//to optimize this SC more we can only use two variable array 
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> cur(2,vector<int>(k+1,0));
        vector<vector<int>> ahead(2,vector<int>(k+1,0));
        // base case: when index == 0 or count == k it will be 0; 
        for(int index = n-1;index>=0;index--){
            for(int buy = 0;buy<2;buy++ ){
                for(int count = 1;count<=k;count++){
                        if(buy){
                            cur[buy][count] = max(
                                        -prices[index] + ahead[0][count],
                                        ahead[1][count]
                                        );
                        }else{
                            cur[buy][count] = max(
                                        prices[index] + ahead[1][count-1],
                                        ahead[0][count]
                            );
                        }
                }
            }
            ahead = cur;
        }
        return ahead[1][k];
    }
};
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