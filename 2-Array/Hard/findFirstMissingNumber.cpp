class Solution {
public:
//direct optimal cause i am cool 
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<nums.size();i++){
            if(nums[i]<=0){
                nums[i] = n+1;
            }
        }
        for(int i =0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(num>0 && num<=nums.size()){
                int index = num-1;
                if(nums[index]>0){
                    nums[index] = -nums[index];
                }
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>0){
                return i+1;
            }
        }
        return n+1;
    }
};

/*
LeetCode 41: First Missing Positive
-----------------------------------
Problem:
    Given an unsorted integer array nums, return the smallest missing positive integer.
    The algorithm must run in O(n) time and use constant extra space.

Key Intuition:
    - Only numbers in the range [1 … n] matter (where n = nums.size()).
    - Any number ≤ 0 or > n is irrelevant (cannot affect the answer).
    - The answer will always be between [1 … n+1].

Approach (Index Marking Trick):
    1. Replace all numbers ≤ 0 with n+1, since they are useless.
    2. For each number 'num' in [1 … n], mark its presence by flipping the sign of nums[num-1].
       - Negative = this number is present.
       - Positive = this number is missing.
    3. Scan the array:
       - The first index i with a positive value means (i+1) is the smallest missing positive.
    4. If all indices are marked (all negative), return n+1.

Time Complexity: O(n)
Space Complexity: O(1)   (in-place marking)

-----------------------------------
Test Cases:

1. nums = [1,2,0]
   → Answer = 3
   (1 and 2 are present, smallest missing positive is 3)

2. nums = [3,4,-1,1]
   → Answer = 2
   (1 and 3 and 4 present, but 2 is missing)

3. nums = [7,8,9,11,12]
   → Answer = 1
   (All numbers are > n, so smallest missing is 1)

4. nums = [1,2,3]
   → Answer = 4
   (All numbers from 1 to n are present, so answer is n+1)

5. nums = [-5,-2,0]
   → Answer = 1
   (No positive numbers at all, so 1 is the answer)

6. nums = [2,3,7,6,8,-1,-10,15]
   → Answer = 1
   (1 is missing, though other large values exist)

7. nums = [2,1]
   → Answer = 3
   (1 and 2 are present, next missing is 3)

-----------------------------------
*/
