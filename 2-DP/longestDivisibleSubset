//brute force: recursion 
/*
class Solution {
public:
    vector<int> solve(vector<int>& nums,int n,int index,int prev){
        if(index >= n) return {};

        //not take 
        vector<int> noTake = solve(nums,n,index+1,prev);
        //take
        vector<int> take;  
        if(prev == - 1 || nums[index] % nums[prev] == 0){
            take = solve(nums,n,index+1,index);
            take.insert(take.begin(),nums[index]);
        }
        return (take.size() > noTake.size())? take : noTake;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return solve(nums,n,0,-1);
    }
};
*/
//better: memoization 
/*
class Solution {
public:
    vector<int> solve(vector<int>& nums,int n,int index,int prev,vector<vector<vector<int>>>& dp){
        if(index >= n) return {};
        if(!dp[index][prev+1].empty()) return dp[index][prev+1]; 
        //not take 
        vector<int> noTake = solve(nums,n,index+1,prev,dp);
        //take
        vector<int> take;  
        if(prev == - 1 || nums[index] % nums[prev] == 0){
            take = solve(nums,n,index+1,index,dp);
            take.insert(take.begin(),nums[index]);
        }
        return dp[index][prev+1] = (take.size() > noTake.size())? take : noTake;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(n+1));
        sort(nums.begin(),nums.end());
        return solve(nums,n,0,-1,dp);
    }
};
*/
//tabulation: 
/*
class Solution {
public:
    vector<int> solve(vector<int>& nums,int n,int index,int prev,vector<vector<vector<int>>>& dp){
        if(index >= n) return {};
        if(!dp[index][prev+1].empty()) return dp[index][prev+1]; 
        //not take 
        vector<int> noTake = solve(nums,n,index+1,prev,dp);
        //take
        vector<int> take;  
        if(prev == - 1 || nums[index] % nums[prev] == 0){
            take = solve(nums,n,index+1,index,dp);
            take.insert(take.begin(),nums[index]);
        }
        return dp[index][prev+1] = (take.size() > noTake.size())? take : noTake;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1));
        sort(nums.begin(),nums.end());
        
        return solve(nums,n,0,-1,dp);
    }
};
*/
//most optimal one: using tabulation and 1 DP 

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
                int n = nums.size();
                vector<int> dp(n,1);
                vector<int> mapp(n+1);
                int maxi = INT_MIN;
                int start = 0 ;
                sort(nums.begin(),nums.end());
                for(int i = 0;i<n;i++){
                    mapp[i] = i;
                    for(int j = 0;j<i;j++){
                        if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
                            dp[i] = dp[j] + 1;
                            mapp[i] = j;
                        }
                    }
                    if(dp[i]>maxi){
                        maxi = dp[i];
                        start = i;
                    }
                }

                vector<int> temp;
                temp.push_back(nums[start]);
                while(mapp[start] != start) {
                    start = mapp[start];
                    temp.push_back(nums[start]);
                }
                reverse(temp.begin(),temp.end());
                return temp;
    }
};


