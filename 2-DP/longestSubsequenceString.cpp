//brute force 
/*
    1. find the subsequence of text1 & text2
    2. return the common one's 
*/

//optimal solution 
/*
    1. maintain the m * n matrix for each string characters 
    2. if find the common characters the dp[i][j] = dp[i-1][j-1] + 1
    3. else dp[i][j] = max(dp[i][j-1],dp[i-1][j])
    return the [n-1] [m-1]   
    Note: in case if their is one of the strings are empty we are making matrix m+1 n+1
    first row and column for each strings empty character that's why we are starting from 1 
    not by 0 
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i = 1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(text1[i-1] == text2[j-1] ) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

//TC: O(n^2)
//SC: O(n^2)