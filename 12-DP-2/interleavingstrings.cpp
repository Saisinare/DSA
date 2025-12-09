//can you create s3 by combining string 1 and 2 without changing its order 

//brute force: use basic recursion 
/*
    2 choices: 
        1. select character from 1st string 
        2. from 2nd string 

gets the MLE error 
*/
// class Solution {
// public:
//     bool solve(string s1, string s2, string s3,int i,int j,int k){
//         if(i==s1.size() && j==s2.size() && k==s3.size()) return true;

//         bool ans = false;
//         if(i<s1.size() && s1[i] == s3[k]){
//             ans = ans || solve(s1,s2,s3,i+1,j,k+1);
//         }
//         if(j<s2.size() && s2[j] == s3[k]){
//             ans = ans || solve(s1,s2,s3,i,j+1,k+1);
//         }
//         return ans;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         return solve(s1,s2,s3,0,0,0);
//     }
// };

//better approach: use memoization 
// class Solution {
// public:
//     bool solve(string s1, string s2, string s3,int i,int j,vector<vector<int>> &dp){
//         int k = i + j;
//         if(k==s3.size()){
//             return (i==s1.size() && j == s2.size());
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
//         bool ans = false;
//         if(i<s1.size() && s1[i] == s3[k]){
//             ans = ans || solve(s1,s2,s3,i+1,j,dp);
//         }
//         if(j<s2.size() && s2[j] == s3[k]  ){
//             ans = ans || solve(s1,s2,s3,i,j+1,dp);
//         }
//         return dp[i][j] = ans;
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//         if(s1.size() + s2.size() != s3.size()) return false;
//         vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
//         return solve(s1,s2,s3,0,0,dp);
//     }
// };

//most optimal solution : tabulazation 

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if( m + n != s3.size() ) return false;
        vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
        //base case 
        dp[0][0] = true;

        //fill out first row and col 
        for(int i = 1;i<=m;i++){
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }
        for(int j = 1;j<=n;j++){
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        //fill the rest of table 
        for(int i = 1 ;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return dp[m][n];
    }
};