#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i =0 ;i<n;i++){
            bool swapped = false;
            for(int j = 0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    swapped = true;
                    swap(nums[j],nums[j+1]);
                } 
            }
            if(!swapped) return nums;
        }
        return nums;
    }
};


int main(){
    vector<int> arr = {4,1,3,9,7};
    Solution solution = Solution();
    solution.bubbleSort(arr);
    for(int i=0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    return 0;
}