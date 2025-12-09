//brute force solution 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0 ;
        for(int i =0;i<nums.size();i++){
            int len = 0;
            int count = 0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]==0){
                    count++;
                }
                if(count<=k){
                    len = j - i + 1;
                    maxLen = max(len,maxLen);
                }
            }
        }
        return maxLen;
    }
};

//O(N^2)

//better 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 ;
        int right = 0 ;
        int zeros = 0 ;
        int maxLen = 0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            while(zeros>k){
                if(nums[left]==0) zeros--;
                left++;
            }
            if(zeros<=k){
                maxLen = max(right-left+1,maxLen);
            }
            right++;
        }
        return maxLen;
    }
};
//O(2n)

//optimal 
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 ;
        int right = 0 ;
        int zeros = 0 ;
        int maxLen = 0;
        while(right<nums.size()){
            if(nums[right]==0) zeros++;
            if(zeros>k){
                if(nums[left]==0) zeros--;
                left ++;
            }
            if(zeros<=k){
                maxLen = max(right-left+1,maxLen);
            }
            right++;
        }
        return maxLen;
    }
};
//O(N)