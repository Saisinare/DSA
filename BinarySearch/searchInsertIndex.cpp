#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0 ;
        int high = n - 1;
        int result = n;
        while(low <= high ){
            int mid = (low+high)/2;
            if(nums[mid] >= target){
                result = mid;
                high = mid - 1 ;
            }
            else {
                low = mid+1;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    
    int index = solution.searchInsert(nums, target);
    std::cout << "Insert position: " << index << std::endl;

    return 0;
}
