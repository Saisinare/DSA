    // class Solution {
    //   public:
    //     int solve(vector<int>& arr,int n,int index,int pre_index,vector<vector<int>>& dp){
    //         if(index >=n) return 0;
    //         if(dp[index][pre_index+1] != -1) return dp[index][pre_index+1]; 
    //         int len = solve(arr,n,index+1,pre_index,dp);
    //         if(pre_index == -1 || arr[index] > arr[pre_index]){
    //             len =  max(len,1 + solve(arr,n,index+1,index,dp));
    //         }
    //         return dp[index][pre_index+1] = len;
    //     }
    //     int lis(vector<int>& arr) {
    //         int n = arr.size();
    //         //we cannot use the arr[-1] but sometimes we call at index -1 so we keep the pre_index size n + 1
    //         vector<vector<int>> dp (n,vector<int>(n+1,-1));
    //         return solve(arr,n,0,-1,dp);
    //     }
    // };
    
    //tabulation 
    
    /*
    class Solution {
      public:
        int lis(vector<int>& arr) {
            int n = arr.size();
            //we cannot use the arr[-1] but sometimes we call at index -1 so we keep the pre_index size n + 1
            vector<vector<int>> dp (n+1,vector<int>(n+1,-1));
            //base case 
            for(int i = 0 ;i<n+1;i++){
                dp[n][i] = 0;
            }
            for(int index = n-1 ;index>=0;index--){
                for(int pre_index = index-1 ;pre_index>=-1;pre_index--){
                    int len = dp[index+1][pre_index+1];
                    if(pre_index == -1 || arr[index] > arr[pre_index]){
                        len =  max(len,1 + dp[index+1][index+1]);
                    }
                    dp[index][pre_index+1] = len;
                }
            }
            return dp[0][0];
        }
    };
   */ 
//optimized one: using DP 
/*
    class Solution {
      public:
        int lis(vector<int>& arr) {
            int n = arr.size();
            //we cannot use the arr[-1] but sometimes we call at index -1 so we keep the pre_index size n + 1
            vector<int> current (n+1,0);
            vector<int> ahead (n+1,0);
            //base case
            for(int index = n-1 ;index>=0;index--){
                for(int pre_index = index-1 ;pre_index>=-1;pre_index--){
                    int len = ahead[pre_index+1];
                    if(pre_index == -1 || arr[index] > arr[pre_index]){
                        len =  max(len,1 + ahead[index+1]);
                    }
                    current[pre_index+1] = len;
                }
                ahead = current;
            }
            return ahead[0];
        }
    };
    */
//most optimal memoization DP
#include<bits/stdc++.h>
using namespace std;
    class Solution {
        public:
            int lis(vector<int>& arr) {
                
                int n = arr.size();
                vector<int> dp(n,1);
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<=i;j++){
                        if(arr[i] > arr[j] && dp[j] + 1 > dp[i]){
                            dp[i] = dp[j] + 1;
                        }
                    }
                }
                return *max_element(dp.begin(),dp.end());
                
            }
        };
//most optimal using binary search 
// #include<bits/stdc++.h>
// using namespace std;
//     class Solution {
//       public:
//     int lis(vector<int>& arr) {
//     vector<int> temp;
//     temp.push_back(arr[0]);

//     for(int i = 1; i < arr.size(); i++) {
//         if(arr[i] > temp.back()) {
//             temp.push_back(arr[i]);
//         } else {
//             int idx = lower_bound(temp.begin(),temp.end(), arr[i]) - temp.begin();
//             temp[idx] = arr[i];
//         }
//     }
//     return temp.size();
//         }
//     };
    

