#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                temp.push_back(nums[i]);
            }
        }
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }

        for(int i=temp.size();i<nums.size();i++){
            nums[i] = 0;
        }
    }
    void moveZeroesOptimal(vector<int>& nums) {
        int j = -1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0 ){
                j = i;
                break;
            }
        }
        if(j == -1){
            return;
        }
        for(int i=j+1;i<nums.size();i++){
            if(nums[i] != 0){
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }

    }
};
int main(){
    vector<int> arr = {1,2,3,4,0,0,5,2};
    Solution sl = Solution();
    sl.moveZeroesOptimal(arr);
    for(int i =0 ;i<arr.size();i++){
        cout<<arr[i];
    }
}