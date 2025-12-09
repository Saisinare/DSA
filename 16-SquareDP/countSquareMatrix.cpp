//brute force: 
/*
    Run across entire matrix and expand its view to the bottom right side 
    every time incrase the count of
*/

//optimal : tabulation
/*
    1. create a dp matrix of same as matrix 
    2. at every dp[i][j] check how many squares are their ending at dp[i][j]
    3. set first row and column as 1 as they are their own right bottom 
    4. while filling the other cells dp[i][j] += min(dp[i-1][j],dp[i][j-1],dp[i-1][j-1])  
    5. return the summation of dp matrix 

*/
/*
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0 ;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i = 0 ; i<m;i++){
            for(int j= 0;j<n;j++){
                if(matrix[i][j] == 1) {
                    if(i==0 || j==0) dp[i][j] = 1;
                    else dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
                }
                sum += dp[i][j];
            }
        }
        return sum;
    }
};
*/
/*
    TC: N^2  
    SC: N^2
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int sum = 0 ;
        for(int i = 0 ; i<m;i++){
            for(int j= 0;j<n;j++){
                if(matrix[i][j] == 1 && j>0 && i>0) {
                    matrix[i][j] = 1 + min(matrix[i][j-1],min(matrix[i-1][j],matrix[i-1][j-1]));
                }
                sum += matrix[i][j];
            }
        }
        return sum;
    }
};

