//Problem 
/*
    Can you divide array into 2 subsequence who's sum will be same 
*/
//Solution 
/*
    if array has odd sum then answer is false as we cannot divide odd things into two parts 
    find only if their is subsequence having sum = totalSum/2
    if yes then create its subsequence and other remaining elements in the array 
*/
class Solution {
public:
    bool solve(vector<int>& nums,int target, int index,int n){
        if(target==0) return true;
        if(target<0 || index >= n) return false;
        bool incl = solve(nums,target-nums[index],index+1,n);
        bool excl = solve(nums,target,index+1,n);

        return incl || excl;

    }
    bool canPartition(vector<int>& nums) {
        int sum = 0 ;
        int n = nums.size();
        for(int i =0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0) return false;
        return solve(nums,sum/2,0,n);
    }
};