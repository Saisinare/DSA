// You are given a circular array nums.

// For each element in nums[i], you need to find the next greater element:

// That means: starting from index i+1, moving forward in the array, you want the first element that is strictly greater than nums[i].

// Since the array is circular, if you reach the end, you continue checking from the beginning.

// If no such element exists, return -1 for that index.


/*
1.brute force solution: 
    1. pick a one element 
    2. find the greater element than this in array 
    3. if we reach end of the array just start from searching 0 index (use modules)
    4. continue this until j!=i

    edge cases: 
        1. if array has only one element that return directly -1 array 
        2. do not forgot about the modules so the index will not be out of bound 

    Complexity: 
        1. Time (O(N^2))
        2. Space (O(N))
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        if(nums.size()==1) return ans;
        for(int i =0;i<nums.size();i++){
            int j = (i+1)%n;
            while(j!=i){
                if(nums[j]>nums[i]){
                    ans[i] = nums[j];
                    break;
                }
                j = (j+1)%n;
            }
        }
        return ans;
    }
};