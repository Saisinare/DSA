#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> hashmap;
        for(int i = 0 ;i<n+1;i++){
            hashmap[i] = 0;
        }
        for(int i = 1;i<n+1;i++){
            hashmap.at(nums[i-1]) = 1;
        }
        for(int i = 0;i<n+1;i++){
            if(hashmap[i] == 0){
                return i;
            }
        }
        return -1;
    }
    int missingNumberBetter(vector<int>& nums) {
        int sum = (nums.size()*(nums.size()+1))/2;
        int s = 0 ;
        for(int i = 0;i<nums.size();i++){
            s += nums[i];
        }
        return sum - s;
    }
    int missingNumberOptimal1(vector<int>& nums) {
        int xor1 = 0;
        int xor2 = 0;
        for(int i =0;i<nums.size();i++){
            xor1 = xor1^nums[i];
            xor2 = xor2^i;
        }
        xor2 = xor2^(nums.size());
        return xor1 ^ xor2;
    }
    int missingNumberOptimal2(vector<int>& nums) {
        int sum = (nums.size()*(nums.size()+1))/2;
        int s = 0 ;
        for(int i = 0;i<nums.size();i++){
            s += nums[i];
        }
        return sum - s;
    }
};

int main() {
    Solution sol;
    
    vector<int> nums = {3, 0, 1}; // Missing number should be 2

    cout << "Using HashMap Approach: " << sol.missingNumber(nums) << endl;
    cout << "Using Summation Formula (Better): " << sol.missingNumberBetter(nums) << endl;
    cout << "Using XOR Method (Optimal1): " << sol.missingNumberOptimal1(nums) << endl;
    cout << "Using Summation Formula (Optimal2): " << sol.missingNumberOptimal2(nums) << endl;

    return 0;
}
