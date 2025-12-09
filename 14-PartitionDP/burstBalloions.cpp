//brute force (Not working One): 
    /*
        try every permutation of balloons bursting 
        choose 1 balloon burst it and then go to the next 

        But whenever you burst the balloons other balloons getting affected by it as all of the neibours will change 

        So we try a bottom up recursion approach 
    */

//brute force (Working one): 
    /*
        As we are choosing the last balloon which is going to burst its right and left side of all balloons and are already burst so we pick the balloon from right and left boundries 
        [b1,b2,b3,b4,b5,b6]
        1. burst b4 : [b1,b2,b3] [b4] [b5,b6]
        as you know the b4 is the last balloon to exists then it has to exist in the second last step 
        2. so every other balloon will found the combination with the last one 
            [b1,b4] [b2,b4] [b2,b4] [b3,b4] [b4,b5] [b4,b6]
            so if choose any of this as the second last element b4 must exist 
        that's why the formuala will be: 

            int coins = balloons[i-1] * balloons[k] * balloons[j+1] + solve(i,k-1) + solve(k+1,j) 
    */
    /*
class Solution {
public:
    int solve(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        int maxi = INT_MIN;
        for(int k = i;k<=j;k++){
            int cost = nums[i-1] * nums[k] * nums[j+1] + solve(nums,i,k-1) + solve(nums,k+1,j);
            maxi = max(maxi,cost);
        }
        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        return solve(nums,1,n-2);
    }
};
*/
//better approach using the memoization 
/*
class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        int maxi = INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i;k<=j;k++){
            int cost = nums[i-1] * nums[k] * nums[j+1] + solve(nums,i,k-1,dp) + solve(nums,k+1,j,dp);
            maxi = max(maxi,cost);
        }
        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(nums,1,n-2,dp);
    }
};
*/
//optimal usin tabulation 
/*
    Base Case: where i > 0 skip that iteration  
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        for(int i = n-2;i>=1;i--){
            for(int j = 1;j<=n-2;j++){
                if(i>j) continue;
                int maxi = INT_MIN;
                for(int k = i;k<=j;k++){
                    int cost = nums[i-1] * nums[k] * nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};

/*
  TC: O(N^3)
  SC: O(N^2)
*/