class Solution {
public:
//direct optimal cause i am cool 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }
        for(int i =0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(num>0 && num<=nums.size()){
                int index = num-1;
                if(nums[index]>0){
                    nums[index] = -nums[index];
                }
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};