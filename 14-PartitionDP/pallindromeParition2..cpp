//Using recursion 
/*
class Solution {
public:

    bool isPallindrome(string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
    }

    int solve(string s,int n,int i){
        if(i>=n) return 0;

        string temp = "";
        int minCost = INT_MAX ;
        //calculate the cost 
        for(int j = i;j<n ;j++){
            temp+=s[j];
            if(isPallindrome(temp)){
                int cost = 1+solve(s,n,j+1);
                minCost = min(minCost,cost);
            }
        }
        return  minCost;
    }
    
    int minCut(string s) {
        int n = s.size();
        //as the solve method is returning the number of paritions and cuts are paritions-1 then 
        return solve(s,n,0)-1;
    }
};
*/

//Using memoization 
/*
class Solution {
public:

    bool isPallindrome(string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
    }

    int solve(string s,int n,int i,vector<int>& dp){
        if(i>=n) return 0;

        string temp = "";
        int minCost = INT_MAX ;
        //calculate the cost 
        if(dp[i] != -1) return dp[i];
        for(int j = i;j<n ;j++){
            temp+=s[j];
            if(isPallindrome(temp)){
                int cost = 1+solve(s,n,j+1,dp);
                minCost = min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        //as the solve method is returning the number of paritions and cuts are paritions-1 then 
        return solve(s,n,0,dp)-1;
    }
};
*/
//Using tabulation 
/*
class Solution {
public:

    bool isPallindrome(string &str) {
    int left = 0, right = str.size() - 1;
    while (left < right) {
        if (str[left] != str[right])
            return false;
        left++;
        right--;
    }
    return true;
    }
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i = n-1 ;i>=0;i--){
            string temp = "";
            int minCost = INT_MAX ;
            for(int j = i;j<n ;j++){
                temp+=s[j];
                if(isPallindrome(temp)){
                    int cost = 1+dp[j+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
        }
        //as the solve method is returning the number of paritions and cuts are paritions-1 then 
        return dp[0]-1;
    }
};
*/
//to reduce the time complexity from N^3 to N^2 use precomputed pallindrome array instead of checking every time 

//TC: N^2 SC: N^3
class Solution {
public:
    
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        vector<vector<bool>>pall (n+1,vector<bool>(n+1,false));
        for(int i = n-1;i>=0;i--){
            for(int j = i ;j<n;j++){
                if (s[i] == s[j]) {
                    if (j - i <= 2) pall[i][j] = true;
                    else pall[i][j] = pall[i+1][j-1];
                } else {
                    pall[i][j] = false;
                }
            }
        }
        for(int i = n-1 ;i>=0;i--){
            string temp = "";
            int minCost = INT_MAX ;
            for(int j = i;j<n ;j++){
                temp+=s[j];
                if(pall[i][j]){
                    int cost = 1+dp[j+1];
                    minCost = min(minCost,cost);
                }
            }
            dp[i] = minCost;
        }
        //as the solve method is returning the number of paritions and cuts are paritions-1 then 
        return dp[0]-1;
    }
};