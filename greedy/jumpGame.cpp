#include <bits/stdc++.h>
using namespace std;

/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        while(i<n){
            int maxi = INT_MIN;
            int maxi_index = 0;
            for(int j=i;(j<=i+nums[i] && j<n);j++){
                if(nums[j]>maxi){
                    maxi = nums[j];
                    maxi_index = j;
                }
            }
            i=maxi_index;
        }
        if(i>=n) return true;
        return false;
    }
};*/

/*
    1. Maintain the maxIndex 
    
    loop the array 
    if(i>maxindex) return false // you cannot get ahead of maxindex 
    maxindex = max(maxindex,i+nums[i]) // i can jump maximum their  
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i =0;i<n;i++){
            if(i>maxi) return false;
            maxi = max(maxi, i+nums[i]);
        }
        return true;
    }
};

// Time Complexity: O(n) 
// Space Complexity: O(1)

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test case 1: [2,3,1,1,4]" << endl;
    cout << "Can jump: " << (sol.canJump(nums1) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test case 2: [3,2,1,0,4]" << endl;
    cout << "Can jump: " << (sol.canJump(nums2) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 3
    vector<int> nums3 = {0};
    cout << "Test case 3: [0]" << endl;
    cout << "Can jump: " << (sol.canJump(nums3) ? "true" : "false") << endl;
    cout << endl;
    
    // Test case 4
    vector<int> nums4 = {2, 0, 0};
    cout << "Test case 4: [2,0,0]" << endl;
    cout << "Can jump: " << (sol.canJump(nums4) ? "true" : "false") << endl;
    
    return 0;
}