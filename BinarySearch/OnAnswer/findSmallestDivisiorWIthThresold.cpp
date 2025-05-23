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

    int OptimalsmallestDivisor(vector<int>& nums, int threshold) {
        int high = 0 ;
        int low = 1;
        int result = -1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]>high){
                high = nums[i];
            }
        }
        while(low<=high){
            int mid = (high+low)/2;
            int sum = 0 ;
            for(int i =0;i<nums.size();i++){
                sum = sum + ceil((double)nums[i]/mid);
            }
            if(sum<=threshold){
                high = mid - 1 ;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = sol.smallestDivisor(nums, threshold);
    cout << "Smallest Divisor: " << result << endl;

    return 0;
}