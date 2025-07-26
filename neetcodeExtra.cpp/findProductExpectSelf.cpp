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
//O(n^2)

//Better
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans;
        vector<int> sufix(nums.size(),1);
        vector<int> prefix(nums.size(),1);
        for(int i =1;i<nums.size();i++){
            prefix[i] = nums[i-1] * prefix[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){    
            sufix[i] = nums[i+1] * sufix[i+1];
        }
        for(int i=0;i<nums.size();i++){    
            ans.push_back(sufix[i] * prefix[i]);
        }
        return ans;
    }
};
//O(N)
//O(1)

//optimal Solution
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);

        for(int i =1;i<nums.size();i++){
            ans[i] = ans[i-1]*nums[i-1];
        }
        int sufix = 1;
        for(int i=nums.size()-2;i>=0;i--){    
            sufix *= nums[i+1];
            ans[i] *= sufix; 
        }
        return ans;
    }
}; 
//O(N) with O(1) S.C.