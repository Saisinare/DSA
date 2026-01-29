
/*
Approach Explanation:

We need to find the Next Greater Element (NGE) for elements in nums1,
where nums1 is a subset of nums2. For each element in nums1, its NGE 
is defined as the first greater element that appears to its right in nums2. 
If there is no such element, the answer is -1.

How do we solve this efficiently?
------------------------------------------------
1. A naive way would be to scan to the right of each element in nums2, 
   but that would be O(n^2). Instead, we use a stack for efficiency.

2. We traverse nums2 from right to left, because "next greater element" 
   means looking toward the right side. By going from right to left, 
   we can maintain a stack of potential greater elements.

3. The stack always keeps elements in decreasing order (monotonic stack).
   - While the stack’s top is <= current element, we pop it, 
     since it can never be the "next greater" for this element or any to the left.
   - If the stack is not empty after popping, the top is the next greater element.
   - If the stack is empty, then no greater element exists, so result is -1.

4. We store these results in a map {element → nextGreater}, so that 
   for any element in nums1, we can directly retrieve its next greater 
   in O(1) time without recalculating.

5. Finally, for each element in nums1, we look up the map and build the answer.

Why this works:
------------------------------------------------
- Each element is pushed and popped from the stack at most once, 
  so the complexity is O(n) for processing nums2.
- Lookup for nums1 elements is O(m).
- Total time = O(n + m), which is efficient compared to O(n^2).

*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mapp ;
        stack<int> st;
        int n2 = nums2.size();
        for(int i =n2-1;i>=0;i--){
           while(!st.empty() && st.top()<=nums2[i]){
            st.pop();
           } 
           if(st.empty()){
            mapp[nums2[i]] = -1; 
           }else{
            mapp[nums2[i]] = st.top();
           }
           st.push(nums2[i]);
        }
        vector<int> res;
        for(int num : nums1){
            res.push_back(mapp[num]);
        }
        return res;
    }
};

//T.C O(N)
//S.C. O(N)





// This code finds the next greater element for each number in nums1 by checking its position in nums2.
// For each element of nums1, it scans nums2 to the right of its index until it finds a larger element.
// If no greater element is found, the answer remains -1. ✅
// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans(nums1.size(),-1);
//       for(int i =0;i<nums1.size();i++){
//         int idx = -1;
//         for(int j =0;j<nums2.size();j++){
//             if(nums2[j]==nums1[i]) idx = j;
//             if(idx==-1) continue;
//             if(nums2[j]>nums1[i] && j>idx){
//                 ans[i] = nums2[j];
//                 break;
//             }
//         }
//       }  
//     return ans;
//     }
// };

//T.C. O(N^2)
//S.C. O(n1.size())

