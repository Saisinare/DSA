//Brute force Solution 
    /*
        1. loop through the nums using i
        2. for every k element from the i find the maximum using loop 
        3. add the maxi in ans array 

        T.C. - n^2
        S.C. - n
    */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for(int i =0;i<=nums.size()-k;i++){
            int maxi = INT_MIN ;
            for(int j=i;j<i+k;j++){
                maxi = max(maxi,nums[j]);
            }
            ans.push_back(maxi);
        }      
        return ans;
    }
};