#include <bits/stdc++.h>
using namespace std ;
class Solution{
    public:
    // for brute use merge sort
        void sortElementsBetter(vector<int>& nums,int n){
          int count0 = 0;
        int count1 = 0;
        int count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                count0++;
            }else if(nums[i] == 1){
                count1++;
            }
            else{
                count2++;
            }
        }
        int j = 0;
        while(count0>0){
            nums[j] = 0;
            j++;
            count0--;
        }
        while(count1>0){
            nums[j] = 1;
            j++;
            count1--;
        }

        while(count2>0){
            nums[j] = 2;
            j++;
            count2--;
        }

    }
        void sortElementsOptimal(vector<int>&nums , int n){
        int high = n-1;
        int low = 0 ;
        int mid = 0;
        while(mid<=high){
            if(nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                mid++;
                low++;
            }
            else if(nums[mid]==2){
                int temp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = temp;
                high--;
            }else{
                mid++;
            }
        }
    }
};
int main(){
    Solution obj;
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;


    obj.sortElementsOptimal(nums, nums.size());

    cout << "Sorted array (Optimal): ";
    for(int num : nums){
        cout << num << " ";
    }
    cout << endl;


    vector<int> nums2 = {2, 0, 2, 1, 1, 0};


    obj.sortElementsBetter(nums2, nums2.size());

    cout << "Sorted array (Better): ";
    for(int num : nums2){
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
