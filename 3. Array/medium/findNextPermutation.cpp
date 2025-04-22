#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index = -1;
        for(int i =nums.size()-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                index = i;
                break;
            }
        } 
        if (index == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = nums.size()-1;i>index;i--){
            if(nums[i]>nums[index]){
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};

int main(){
    vector<int> arr = {1,3,2};
    Solution sl = Solution();
    sl.nextPermutation(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
    return 0;
}