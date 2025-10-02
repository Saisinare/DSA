// Time Complexity: O(n^2), where n is the size of the input array.
// Space Complexity: O(1).
//brute force 
    /*
        1. Generate all of subarrays using nested loop
        2. while looping in the array keep track of max an min in the subarray 
        3. concurrently add this max - min in the sum
        4. return sum
    */
class Solution {
public:

    long long subArrayRanges(vector<int>& nums) {
        long long sum = 0;
        for(int i =0;i<nums.size();i++){
            int maxi = INT_MIN ,  mini = INT_MAX;
            for(int j =i;j<nums.size();j++){
                cout<<sum;
                maxi = max(maxi,nums[j]);
                mini = min(mini,nums[j]);
                sum = sum +  (maxi - mini);
            }
        }
        return sum;
    }
};

//O(N^2) T.C
//O(1) S.C.