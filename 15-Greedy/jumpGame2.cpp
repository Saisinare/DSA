#include <bits/stdc++.h>
using namespace std;

//using recursion and greedy 
/*
class Solution {
public:
    int solve(vector<int>& nums,int n,int index,int jumps){
        if(index>=n-1) return jumps;
        int mini = INT_MAX;
        for(int i =1;i<=nums[index];i++){
            mini = min(mini,solve(nums,n,index+i,jumps+1));
        }
        return mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,nums.size(),0,0);
    }
};
*/

//using memoization 
/*
class Solution {
public:
    int solve(vector<int>& nums,int n,int index,int jumps,vector<vector<int>>& dp){
        if(index>=n-1) return jumps;
        int mini = INT_MAX;
        if(dp[index][jumps]!=-1)return dp[index][jumps];
        for(int i =1;i<=nums[index];i++){
            mini = min(mini,solve(nums,n,index+i,jumps+1,dp));
        }
        return dp[index][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,nums.size(),0,0,dp);
    }
};
*/
//still getting the TLE 
/*
class Solution {
public:
    int solve(vector<int>& nums,int n,int index,int jumps,vector<vector<int>>& dp){
        if(index>=n-1) return jumps;
        int mini = INT_MAX;
        if(dp[index][jumps]!=-1)return dp[index][jumps];
        for(int i =1;i<=nums[index];i++){
            mini = min(mini,solve(nums,n,index+i,jumps+1,dp));
        }
        return dp[index][jumps] = mini;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,nums.size(),0,0,dp);
    }
};
*/

//using greedy approach 
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0 ;
        int l = 0,r =0;
        int farthest ;
        while(r<n-1){
            farthest = 0; 
            for(int j = l ;j<=r;j++){
                farthest = max(farthest,j+nums[j]);
            }
            l = r +1 ;
            r = farthest;
            jumps ++;
        }
        return jumps;
    }
};

// Time Complexity: O(n) 
// Space Complexity: O(1)

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test case 1: [2,3,1,1,4]" << endl;
    cout << "Minimum jumps: " << sol.jump(nums1) << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {2, 3, 0, 1, 4};
    cout << "Test case 2: [2,3,0,1,4]" << endl;
    cout << "Minimum jumps: " << sol.jump(nums2) << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {1, 2, 3};
    cout << "Test case 3: [1,2,3]" << endl;
    cout << "Minimum jumps: " << sol.jump(nums3) << endl;
    cout << endl;
    
    // Test case 4
    vector<int> nums4 = {1, 1, 1, 1};
    cout << "Test case 4: [1,1,1,1]" << endl;
    cout << "Minimum jumps: " << sol.jump(nums4) << endl;
    cout << endl;
    
    // Test case 5
    vector<int> nums5 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
    cout << "Test case 5: [10,9,8,7,6,5,4,3,2,1,1,0]" << endl;
    cout << "Minimum jumps: " << sol.jump(nums5) << endl;
    
    return 0;
}