// This code finds the next greater element for each number in nums1 by checking its position in nums2.
// For each element of nums1, it scans nums2 to the right of its index until it finds a larger element.
// If no greater element is found, the answer remains -1. ✅
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(),-1);
      for(int i =0;i<nums1.size();i++){
        int idx = -1;
        for(int j =0;j<nums2.size();j++){
            if(nums2[j]==nums1[i]) idx = j;
            if(idx==-1) continue;
            if(nums2[j]>nums1[i] && j>idx){
                ans[i] = nums2[j];
                break;
            }
        }
      }  
    return ans;
    }
};

//T.C. O(N^2)
//S.C. O(n1.size())