class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i<n-3;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j= i+1;j<n-2;j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int low = j+1;
                int high = n-1;
                while(low<high){
                    long long sum = nums[i]+nums[j];
                    sum+= nums[low];
                    sum+= nums[high];
                    if(sum==target){
                        res.push_back({nums[i],nums[j],nums[low],nums[high]});
                    while(low <n-1 && nums[low+1]==nums[low]) low++;
                    while(high > 0 && nums[high]==nums[high-1]) high--;
                        low++;
                        high--;
                    }
                    else if(sum<target){
                        low++;
                    }
                    else if(sum>target){
                        high--;
                    }
                }
            }
        }
        return res;
    }
};
