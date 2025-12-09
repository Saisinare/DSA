class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count = 0 ;
        for(int i =0;i<nums.size();i++){
            set<int> sett ;
            for(int j = i;j<nums.size();j++){
                sett.insert(nums[j]);
                if(sett.size()==k) count++;
                else if(sett.size()>k) break;
            }
        }
        return count;
    }
};

//using O(N^2) T.C and O(N) S.C.


class Solution {
public:
    int findCount (vector<int>& nums, int k){
        int count = 0 ;
        int r = 0, l=0;
        int n = nums.size();
        map<int,int> mapp;
        while(r<n){
            mapp[nums[r]]++;
            while(mapp.size()>k && l<n){
                mapp[nums[l]]--;
                if(mapp[nums[l]]==0) mapp.erase(nums[l]);
                l++;
            }
            if(mapp.size()<=k) count += (r-l+1);
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return findCount(nums,k) - findCount(nums,k-1);
    }
};

/*
Problem: Count the number of subarrays with exactly K distinct integers.

----------------------------------
⚠️ Why a normal sliding window fails?
----------------------------------
Normally, in "longest substring with K distinct" type problems, a sliding window works well 
because we only care about the MAXIMUM length. 
But here, we must count ALL subarrays with EXACTLY K distinct numbers.

Example:
nums = [1,2,1,2,3], k = 2
Valid subarrays: 
[1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,3] → total 7

If we use a simple sliding window that just shrinks when > k,
we can maintain a valid window, but we will MISS counting many subarrays 
that end at different positions inside the window. 
So a plain window doesn’t directly give the count.

----------------------------------
💡 Trick: At Most K – At Most (K-1)
----------------------------------
Idea: 
Instead of directly counting EXACTLY K distinct, we use a helper:
- findCount(nums, k) = number of subarrays with AT MOST k distinct integers
- findCount(nums, k-1) = number of subarrays with AT MOST (k-1) distinct integers
Then:
    EXACTLY k distinct = findCount(k) – findCount(k-1)

Reason: 
Every subarray with exactly K distinct is included in "at most K" 
but excluded from "at most (K-1)". 
So the difference isolates exactly those subarrays.

----------------------------------
🛠️ How findCount works
----------------------------------
Sliding window with 2 pointers (l and r):
- Expand r to include nums[r], increase its count in the map.
- If map.size() > k, shrink window from left (l++) until map.size() ≤ k.
- For each r, all subarrays ending at r with ≤ k distinct start anywhere from l to r.
  So we add (r - l + 1) to the count.

----------------------------------
✅ Complexity
----------------------------------
- Each element is added and removed at most once → O(n).
- Map insert/erase is O(log n), but can be optimized with unordered_map → average O(1).
- Total: O(n log n) with map, O(n) with unordered_map.

This makes it efficient for large inputs.
*/
