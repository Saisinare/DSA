//problem : find no. of different combinations of coins by which we can built to the amount

//brute force : using simple recusion 
    /*
        2 choices: 
            1. either include the coin and stay on the same index 
            2. skip the coin and move ahead;

        class Solution {
public:
    int solve(int index , int amount, vector<int>& coins,int n){ 
        if(amount == 0) return 1;
        if(index==0) return (amount%coins[0] == 0) ? 1 : 0;

        int take = 0 ; 
        if(coins[index]<=amount)
            take = solve(index,amount-coins[index],coins,n);

        int skip = solve(index-1,amount,coins,n);

        return  take + skip;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        //index and count;
        return solve(n-1,amount,coins,n);
    }
};
            
        but this thing gets TLE so lets test memoization 

    */
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int index , int amount, vector<int>& coins,int n,vector<vector<int>>& dp){ 
        if(amount == 0) return 1;
        if(index==0) return (amount%coins[0] == 0) ? 1 : 0;
        
        if(dp[index][amount]!=-1) return dp[index][amount];

        int take = 0 ; 
        if(coins[index]<=amount)
            take = solve(index,amount-coins[index],coins,n,dp);

        int skip = solve(index-1,amount,coins,n,dp);

        return dp[index][amount] =  take + skip;

    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        //index and count;
        return solve(n-1,amount,coins,n,dp);
    }
};