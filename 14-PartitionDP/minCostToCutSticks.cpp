//brute force: recursion
/*
class Solution {
public:
    int solve(int n, vector<int>& cuts,int i ,int j){
        if(i>j) return 0;
        int mini = 1e9;
        int ans = 0 ;
        for(int k = i ;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1];
            int ans = cost + (long long) solve(n,cuts,i,k-1) + solve(n,cuts,k+1,j);
            mini = min(ans,mini);
        }
        return mini;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        
        sort(cuts.begin(),cuts.end());

        return solve(m,cuts,1,m-2);
    }
};
*/
//better: memoization 
/*

class Solution {
public:
    int solve(int n, vector<int>& cuts,int i ,int j,vector<vector<int>>& dp){
        if(i>j) return 0;
        int mini = 1e9;
        int ans = 0 ;
        if(dp[i][j]!=-1) return dp[i][j]; 
        for(int k = i ;k<=j;k++){
            int cost = cuts[j+1]-cuts[i-1];
            int ans = cost + (long long) solve(n,cuts,i,k-1,dp) + solve(n,cuts,k+1,j,dp);
            mini = min(ans,mini);
        }
        return dp[i][j] = mini;

    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        sort(cuts.begin(),cuts.end());

        return solve(m,cuts,1,m-2,dp);
    }
};

*/
//optimal tabulation 

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m+1,vector<int>(m+1,0));
        sort(cuts.begin(),cuts.end());
        //loops: 
        for(int i = m-2;i>=1;i--){
            for(int j = 1;j<=m-2;j++){
                if(i>j) continue;
                int mini = 1e9;
                int ans = 0 ;
                for(int k = i ;k<=j;k++){
                    int cost = cuts[j+1]-cuts[i-1];
                    int ans = cost + dp[i][k-1] + dp[k+1][j];
                    mini = min(ans,mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m-2];
    }
};