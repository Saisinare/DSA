/*
class Solution {
public:
    int solve(vector<int>& arr, int k,int n,int index){
        if(index >= n) return 0;
        int sum = 0 ;
        int maxi = 0;
        int maxiAns = 0;
        int len = 0 ;
        for(int j = index ; j<min(n,index+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            sum = (len*maxi) + solve(arr,k,n,j+1);
            maxiAns = max(maxiAns,sum);
        }
        return maxiAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        return solve(arr,k,n,0);
    }
};
*/
//using memoization: 
/*
class Solution {
public:
    int solve(vector<int>& arr, int k,int n,int index,vector<int>& dp){
        if(index >= n) return 0;
        int sum = 0 ;
        int maxi = 0;
        int maxiAns = 0;
        int len = 0 ;
        if(dp[index] != -1) return dp[index];
        for(int j = index ; j<min(n,index+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            sum = (len*maxi) + solve(arr,k,n,j+1,dp);
            maxiAns = max(maxiAns,sum);
        }
        return dp[index] = maxiAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return solve(arr,k,n,0,dp);
    }
};
*/
//using tabulation: 
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n+1,0);
        for(int index = n-1;index>=0;index--){
            int sum = 0 ;
            int maxi = 0;
            int maxiAns = 0;
            int len = 0 ;
            for(int j = index ; j<min(n,index+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                sum = (len*maxi) + dp[j+1];
                maxiAns = max(maxiAns,sum);
            }
            dp[index] = maxiAns;
        }
        return dp[0];
    }
};