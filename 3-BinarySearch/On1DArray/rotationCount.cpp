class Solution {
public:
    int findKRotation(vector<int> &nums)  {
        int low = 0;
        int high = nums.size()-1;
        int ans = INT_MAX;
        int idx  = -1;
        while(low <= high){
            int mid = low + (high - low) / 2;

            if(nums[low]<=nums[high]){
                if(nums[low] < ans){
                    ans = nums[low];
                    idx = low;
                }
                break;
            }

            if(nums[mid]>=nums[high]){
                if(nums[mid] < ans){
                    ans = nums[mid];
                    idx = mid;
                }   
                low = mid +1 ;
            }else{
                if(nums[mid] < ans){
                    ans = nums[mid];
                    idx = mid;
                }   
                high = mid - 1; 
            }
        }

        return idx; 
    }
};