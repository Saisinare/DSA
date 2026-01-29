#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> insertionSort(vector<int>& nums) {
        int n = nums.size();
        for(int i =0;i<n;i++){
            int j = i;
            while(j>0 && nums[j]<nums[j-1]){
                swap(nums[j],nums[j-1]);
                j--;
            }
        }
        return nums;
    }
};


int main(){
    vector<int> arr = {4,1,3,9,7};
    Solution solution = Solution();
    solution.insertionSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}