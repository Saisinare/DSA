#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        int i =0;
        int j =0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n =n1+n2;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }else{
                result.push_back(nums2[j]);
                j++;
            }
        }
        while(i<n1){
                result.push_back(nums1[i]);
                i++;
        }
        while(j<n2){
            result.push_back(nums2[j]);
            j++;
        }
        if(n%2==1) return (double) result[n/2];
        else return (double)((double)result[n/2] + (double)result[(n/2)-1])/2;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}