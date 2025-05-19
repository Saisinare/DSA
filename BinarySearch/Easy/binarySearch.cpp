
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, int low,int high){
        int mid = (low+high)/2;
        if(low>high) return -1;
        if(nums[mid] == target) return mid;
        else if(nums[mid] < target) 
            return binarySearch(nums,target,mid+1,high);
        else
            return binarySearch(nums,target,low,mid-1);
    }
    int search(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1;
            return binarySearch(nums,target,low,high);
    }
    //break for today
};


int main() {
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    int target = 5;
    
    int result = sol.search(nums, target);
    cout << "Index of target " << target << " is: " << result << endl;

    return 0;
}
