#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0 ;
        int rob2 = 0 ;
        for(int current:nums){
            int temp = max(current+rob1,rob2);
            rob1 = rob2;
            rob2 = temp;
        } 
        return rob2;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)