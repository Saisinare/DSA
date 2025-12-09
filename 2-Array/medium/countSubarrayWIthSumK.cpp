#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count = 0 ;
       map<int,int> hash;
       hash[0] = 1;
       int preSum = 0 ;
       for(int i =0;i<nums.size();i++){
        preSum += nums[i];
        int remove = preSum - k;
        count += hash[remove];
        hash[preSum] += 1;
       } 
       return count;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    int result = sol.subarraySum(nums, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    return 0;
}
