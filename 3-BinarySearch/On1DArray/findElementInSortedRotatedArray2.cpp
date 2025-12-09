#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target){
                return true;
            }
            if(nums[mid] == nums[low] && nums[mid] == nums[high]){
                high = high-1;
                low = low+1;
                continue;
            }
            if(nums[low]<=nums[mid]){
                if(nums[low]<=target && target<=nums[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else if(nums[high]>=nums[mid]){
                if(target<=nums[high] &&  target>=nums[mid]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    if (sol.search(nums, target)) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
