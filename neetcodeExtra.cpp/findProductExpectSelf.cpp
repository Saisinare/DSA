//brute force 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        for(int i =0;i<nums.size();i++){
            long long product = 1;
            for(int j =0;j<nums.size();j++){
                if(j!=i){
                    product *= nums[j]; 
                }
            }
            ans.push_back(product);
        }
        return ans;
    }
};