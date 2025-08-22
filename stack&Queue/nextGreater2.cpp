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

//optimal Solution

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i =2*n-1;i>=0;i--){
            int idx = i%n;
            while(!st.empty() && nums[idx]>=nums[st.top()]){
                st.pop();
            }
            if(!st.empty()){
                ans[idx] = nums[st.top()];
            }
            st.push(idx);
        }
        return ans;
    }
};


// Approach (Monotonic Stack):
// 1. We traverse the array in reverse order twice (2*n - 1 → 0) to simulate circular behavior.
// 2. We use a monotonic decreasing stack that stores indices of elements. 
//    - While the stack is not empty and nums[idx] >= nums[st.top()], we pop from stack.
//    - This ensures stack always contains indices of elements in decreasing order of their values.
// 3. If the stack is not empty after popping, the top element of the stack is the Next Greater Element.
//    Otherwise, we leave -1 (default value).
// 4. Push the current index onto the stack for future elements.
//
// Why reverse traversal?
// - We traverse backwards so that when we process an element, its "future" (right side elements) 
//   are already considered and stored in stack, allowing efficient lookup.
//
// Time Complexity:
// - Each element is pushed and popped from the stack at most once → O(n).
// - We traverse 2n elements in the loop → O(2n) ≈ O(n).
// Overall: O(n)
// Space Complexity: O(n) for the stack + O(n) for answer vector → O(n)