#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        if(nums.size() == 0) return nums[0];
        while(low <= high){
            int mid = low + (high-low)/2;
            if((mid == 0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1] ))return mid;
            else if((mid == 0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]<nums[mid+1])){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 2, 3, 1};
    int peakIndex = sol.findPeakElement(nums);
    std::cout << "Peak element index: " << peakIndex << std::endl;
    return 0;
}
