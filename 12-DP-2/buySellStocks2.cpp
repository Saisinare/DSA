//brute force: using recursion only 

//two possibilities 
/*
    1. buy 
        you can buy it today and you will not have liberty to buy next day
        you do not buy it today and you will not have liberty to buy it on the next day
    2. sell (don't buy)
        you can sell it today and have liberty to buy on next day
        you do not sell it today and not have libery to buy it on the next day 
    in each cases return the minimum out of two 

    base case : index>=n
    can buy = 1
    cannot buy = 0 
*/

//TC: 2^n
//SC: N 

//This will get the TLE 
// class Solution {
// public:
//     long long solve(vector<int>& prices,int index,int n,int buy){
//         long long profit = 0;
//         if(index>=n){
//             return 0;
//         }
//         if(buy){
//             profit = max(profit, max(-prices[index] + solve(prices,index+1,n,0),solve(prices,index+1,n,1)));
//         }else{
//             profit = max( profit,max(prices[index] + solve(prices,index+1,n,1), solve(prices,index+1,n,0)));
//         }
//         return profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         return solve(prices,0,prices.size(),1);
//     }
// };


//better way : Using memoization cause their are overlapping subproblems 
/*
    their are two changing prameters (index,buy/sell)

    TC : O(n^2);
    SC : O(N) + O(n^2)
*/
/*
class Solution {
public:
    long long solve(vector<int>& prices,vector<vector<int>>& dp,int index,int n,int buy){
        long long profit = 0;
        if(index>=n){
            return 0;
        }
        if(dp[index][buy] != -1) return dp[index][buy];
        if(buy){
            profit = max(profit, max(-prices[index] + solve(prices,dp,index+1,n,0),solve(prices,dp,index+1,n,1)));
        }else{
            profit = max( profit,max(prices[index] + solve(prices,dp,index+1,n,1), solve(prices,dp,index+1,n,0)));
        }
        return dp[index][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(prices,dp,0,n,1);
    }
};
*/

//optimal way: to reduce the oxilary space of the recursion stack use tabulation 
/*
    base case : when i == n then profit will be 0 for both cases sell and buy 
    //TC : O(N^2)
    //SC : O(N^2)
*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1,vector<int>(2,0));
//         dp[n][0] = dp[n][1] =  0; 
//         for(int index = n-1 ;index>=0;index--){
//             for(int buy = 0;buy<2;buy++){
//                         int profit = 0;
//                         if(buy){
//                             profit = max(-prices[index] + dp[index+1][0],dp[index+1][1]);
//                         }else{
//                             profit = max(prices[index] + dp[index+1][1], dp[index+1][0]);
//                         }
//                         dp[index][buy] = profit;
//             }
//         }

//         return dp[0][1];
//     }
// };

//reducee the dp space and make it in 1 DP 
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<long> ahead(2,0),cur(2,0); // we can use 4 variable instead of this 2 arrays but it will be same 
        ahead[0] = ahead[1] =  0; 
        for(int index = n-1 ;index>=0;index--){
            for(int buy = 0;buy<2;buy++){
                        int profit = 0;
                        if(buy){
                            profit = max(-prices[index] + ahead[0],ahead[1]);
                        }else{
                            profit = max(prices[index] + ahead[1], ahead[0]);
                        }
                        cur[buy] = profit;
            }
            ahead = cur;
        }

        return ahead[1];
    }
};
*/

//Using 4 variables and using 2 arrays are the same in Time and Space Complexity so use the previous one code 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        long aheadBuy = 0, aheadSell = 0;
        long curBuy = 0, curSell = 0;

        for (int index = n - 1; index >= 0; index--) {
            // If we can buy at this index
            curBuy = max(-prices[index] + aheadSell, aheadBuy);

            // If we can sell at this index
            curSell = max(prices[index] + aheadBuy, aheadSell);

            // Move current state to ahead for next iteration
            aheadBuy = curBuy;
            aheadSell = curSell;
        }

        // Initially, we are allowed to buy
        return aheadBuy;
    }
};
