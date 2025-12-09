/*
class Solution {
  public:
    int solve(vector<int> &arr,int i , int j,vector<vector<int>>& dp){
        if(i==j) return 0;
        int mini = 1e9 ; 
        int ans = 0 ;
        if(dp[i][j] != -1 ) return dp[i][j];
        for(int k = i;k<j;k++){
            ans = (arr[i-1] * arr[k] * arr[j]) + 
            solve(arr,i,k,dp) + 
            solve(arr,k+1,j,dp) ;
            mini = min(mini,ans);
        }
        return dp[i][j] = mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here

        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr,1,n-1,dp);
    }
};
*/

//using tabulation 
class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int i = n-1; i>=1;i--){
            for(int j=i+1;j<n;j++){
                int mini = 1e9 ; 
                int ans = 0 ;
                for(int k = i;k<j;k++){
                    ans = (arr[i-1] * arr[k] * arr[j]) + 
                    dp[i][k] + 
                    dp[k+1][j] ;
                    mini = min(mini,ans);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][n-1];
    }
};