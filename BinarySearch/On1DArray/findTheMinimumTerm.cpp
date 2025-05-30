#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high=nums.size()-1, answer = INT_MAX;

        while(low<=high){
            int mid = (low+high)/2;
            if(nums[mid]<=nums[high]){
                answer = min(answer,nums[mid]);
                high = mid-1;
            }else{
                answer = min(answer,nums[low]);
                low = mid+1;
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int result = solution.findMin(nums);
    cout << "Minimum element is: " << result << std::endl;
    return 0;
}


