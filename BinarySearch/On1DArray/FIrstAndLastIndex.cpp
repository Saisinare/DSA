#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0 ;
        int high = nums.size()-1;
        int start = -1,end = -1;
        int n = nums.size();
        vector<int> result;
        while(low<= high){
            int mid = (low+high)/2;
            if(nums[mid] == target) 
            {
                start = mid;
                end = mid;
                break;
            }
            else if(target > nums[mid]) low = mid+1;
            else high = mid-1; 
        }
        if(start != -1 && end != -1 ){
            while( start>0 && nums[start-1] == target ){
                start--;
            }
            while(end<n-1 && nums[end+1] == target ){
                end++;
            }
        }
        result.push_back(start);
        result.push_back(end);
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    
    vector<int> result = sol.searchRange(nums, target);
    
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
