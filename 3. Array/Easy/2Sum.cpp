#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    vector<int> result;
    vector<int> twoSum(vector<int> &nums,int target){
        for(int i =0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                if(nums[i] + nums[j] == target){
                    result = {i,j};
                    return result;
                }
            }
        }
        return result;
    }

};
int main() {
    vector<int> nums = {2, 7, 11, 15};  
    int target = 9;

    Solution sol;
    vector<int> result = sol.twoSum(nums, target);

    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two numbers add up to the target." << endl;
    }

    return 0;
}