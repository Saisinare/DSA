#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int>& nums) {
        int maxi = INT_MIN;
        vector<int> ans;
      for(int i =nums.size()-1;i>=0;i--){
        if(nums[i]>maxi){
            maxi = nums[i] ;
            ans.push_back(maxi);
        }
      }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
int main() {
    Solution sol;
    vector<int> nums = {16, 17, 4, 3, 5, 2};
    vector<int> result = sol.leaders(nums);

    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
