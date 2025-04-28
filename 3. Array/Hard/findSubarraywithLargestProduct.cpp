#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prefix = 1 ;
        int sufix = 1 ;
        int maxi = INT_MIN;
        for(int i =0;i<nums.size();i++){
            if(prefix == 0 ) prefix = 1;
            if(sufix == 0) sufix = 1;
            prefix = prefix * nums[i];
            sufix = sufix * nums[nums.size()-i-1];
            maxi = max(maxi,max(prefix,sufix));
        }
        return maxi;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {2, 3, -2, 4}; // Example input
    int result = sol.maxProduct(nums);
    cout << "Maximum product subarray: " << result << endl;
    return 0;
}