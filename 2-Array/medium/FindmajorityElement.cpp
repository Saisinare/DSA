#include<bits/stdc++.h>
using namespace std ;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        for(int i =0;i<nums.size();i++){
            int count = 0 ;
            for(int j=0;j<nums.size();j++){
                if(nums[j] == nums[i]){
                    count++;
                }
            }
            if(count>nums.size()/2){
                return nums[i];
            };
        }
        return -1;
    }
    int majorityElementBetter(vector<int>& nums) {
        map<int,int> mapp ;
        for(int i=0;i<nums.size();i++){
            mapp[nums[i]]++;
        }
        for(auto it:mapp){
            if(it.second>(nums.size()/2)){
                return it.first;
            }
        }
        return -1;
    }
    int majorityElementOptimal(vector<int>& nums) {
        int ele;
        int count = 0;
        for(int i=0;i<nums.size();i++){
            if(count ==0 ){
                ele = nums[i];
            }
            if(ele == nums[i]){
                count++;
            }else{
                count -- ;
            }
        }
        count = 0;
        for(int i =0;i<nums.size();i++){
            if(ele==nums[i]){
                count++;
            }
        }
        if(count>nums.size()/2){
            return ele;
        };
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Brute Force: " << sol.majorityElement(nums) << endl;
    cout << "Better Approach (Map): " << sol.majorityElementBetter(nums) << endl;
    cout << "Optimal Approach (Boyer-Moore): " << sol.majorityElementOptimal(nums) << endl;

    return 0;
}
