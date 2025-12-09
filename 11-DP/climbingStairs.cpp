// Recursion tree for n=4:
//
//                   climb(4)
//                 /         \
//           climb(3)         climb(2)
//           /     \          /     \
//     climb(2)  climb(1)  climb(1)  climb(0)
//     /     \
//  climb(1) climb(0)
//
// As you can see, the left and the right part of the tree repeat the same function calls.
// To avoid recomputation, we store the results of subproblems (memoization).
//
// Using DP (bottom-up), we only need the last two results at any time, 
// so space complexity can be reduced to O(1).
//
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Initialization:
// - climb(0) = 1 (1 way: do nothing, already at floor 0)
// - climb(1) = 1 (1 way: single step)
// These correspond to the two variables we keep.
//
// Then we iterate from 2 to n and update the variables:
// ways[i] = ways[i-1] + ways[i-2]


class Solution {
public:
    int climbStairs(int n) {
        int one = 1 ;
        int two = 1 ;
        for(int i =0;i<n-1;i++){
            // the first step (1) is already counted in initialization (one = 1, two = 1), so you only need n-1 updates to reach step n. ✅ 
            int temp = one;
            one = one + two;
            two = temp;
        }
        return one;
    }
};
