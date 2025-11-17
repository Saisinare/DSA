//find the length 
/*
    len = m + n - (LCS)
*/
//find the SCS string 
/*
    1. make the DP table 
    2. backtrack from the table and add the according characters to the ans string 
        1. Start from the 0,0
        2. use the inverse conditions for ans construction which are used for constructing the DP table 

*/
class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
        string ans = "";
        int m = str1.size();
        int n = str2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = m-1 ;i>=0 ;i--){
            for(int j = n-1; j>=0; j--){
                if(str1[i] == str2[j]){ 
                    dp[i][j] = 1+dp[i+1][j+1] ;
                }
                else dp[i][j] = max (dp[i+1][j] , dp[i][j+1]);
            }
        }

        int i = 0 ;
        int j = 0 ;
        while(i<m && j<n){
            if(str1[i] == str2[j]){
                ans += str1[i];
                i++;
                j++;
            }else if(dp[i][j+1] > dp[i+1][j]){
                //right 
                ans += str2[j];
                j++;
            }else{
                //up
                ans += str1[i];
                i++;
            }
        }
        while(i<m){
          ans += str1[i];
          i++;  
        } 
        while(j<n){
            ans += str2[j];
            j++;
        }
        return ans;
    }
};