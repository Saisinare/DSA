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
