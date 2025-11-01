//brute force: recursion 
/*
    1. same as the stocks buy sell 2 problem but include the limit to transaction 
    
    cases: 1.   can buy : 
                    1. buyed and cannot buy tommarow 
                    2. not buyed and can buy tommarow 
           2.   can sell :
                    1. selled and can buy tommarow 
                    2. not selled and cannot buy tommarow 
*/
/*
    class Solution {
    public:
        int solve(vector<int>& prices,int n,int index,int buy, int count){
            //base case
            if(index >= n || count == 2) return 0;
            int profit = 0;
            if(buy){
                profit = max({
                            -prices[index] + solve(prices,n,index+1,0,count),
                            solve(prices,n,index+1,1,count)
                            });
            }else{
                profit = max({
                        prices[index] + solve(prices,n,index+1,1,count+1),
                            solve(prices,n,index+1,0,count)
                            });
            }
            return profit;
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            return solve(prices,n,0,1,0);
        }
    };
*/
/*
    Time Complexity: (2^n)
    Space Complexity: (N)
*/

//Better: using memoization 
/*
class Solution {
public:
    int solve(vector<int>& prices,int n,int index,int buy, int count,vector<vector<vector<int>>>& dp){
        //base case
        if(index >= n || count == 2) return 0;
        int profit = 0;
        if(dp[index][buy][count] != -1) return dp[index][buy][count];
        if(buy){
            profit = max(
                        -prices[index] + solve(prices,n,index+1,0,count,dp),
                        solve(prices,n,index+1,1,count,dp)
                        );
        }else{
            profit = max(
                    prices[index] + solve(prices,n,index+1,1,count+1,dp),
                        solve(prices,n,index+1,0,count,dp)
                        );
        }
        return dp[index][buy][count] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(prices,n,0,1,0,dp);
    }
};
*/
//sometimes using max({elements}) can cause the TLE  
/*
    TC : O(N) 
    SC : O(N*3*2)
*/

//use only 2 (3x2) arrays: to reduce TC 
    /*
        create a cur and prev 
    */
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp (n+1,vector<vector<int>>(2,vector<int>(3,-1)));

        //set the last cell as 0 
        for(int i = 0 ; i<2 ; i++){
            for(int j = 0 ; j<3 ; j++){
                dp[n][i][j] = 0;
            }
        }

        //set the cell = 0 where count = 0

        for(int i = 0 ;i<=n;i++){
            for(int j = 0 ;j<2;j++){
                dp[i][j][2] = 0;
            }
        }

        //now fill the rest of the array 
        for(int i = n-1;i>=0 ;i--){
            for(int buy = 0 ;buy<2;buy++){
                for(int count = 0;count<2;count++){
                            if(buy){
                                dp[i][buy][count] = max(
                                -prices[i] +  dp[i+1][0][count],
                                dp[i+1][1][count]
                                );
                            }else{
                                dp[i][buy][count] = max(
                                prices[i] + dp[i+1][1][count+1],
                                dp[i+1][0][count]
                                );
                            }
                }
            }
        }
        return dp[0][1][0];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> ahead (2,vector<int>(3,0));
        vector<vector<int>> cur (2,vector<int>(3,0));


        //now fill the rest of the array 
        for(int i = n-1;i>=0 ;i--){
            for(int buy = 0 ;buy<2;buy++){
                for(int count = 0;count<2;count++){
                            if(buy){
                                cur[buy][count] = max(
                                -prices[i] +  ahead[0][count],
                                ahead[1][count]
                                );
                            }else{
                                cur[buy][count] = max(
                                prices[i] + ahead[1][count+1],
                                ahead[0][count]
                                );
                            }
                }
            }
                ahead = cur;
        }
        return ahead[1][0];
    }
};

