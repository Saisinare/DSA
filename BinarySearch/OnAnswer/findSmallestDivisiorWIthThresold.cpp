#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = 0 ;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi = nums[i];
            }
        }
        for(int d = 1;d<=maxi;d++){
            int sum = 0 ;
            for(int i =0;i<nums.size();i++){
                sum = sum + ceil((double)nums[i]/d);
            }
            if(sum<=threshold){
                return d;
            }
        }
        return -1;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}