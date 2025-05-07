#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid] == target) return mid;
            if(nums[low]<=nums[mid]){
                if(nums[low]<= target && nums[mid]>=target){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }else if(nums[high]>=nums[mid]){
                if(target>=nums[mid] && target<=nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};


int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2}; 
    int target = 0; 

    int result = solution.search(nums, target);
    if (result != -1) {
        cout << "Target found at index: " << result << endl;
    } else {
        cout << "Target not found" << endl;
    }

    return 0;
}