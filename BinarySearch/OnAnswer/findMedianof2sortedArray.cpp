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


    double OptimalfindMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i =0;
        int j =0;
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n =n1+n2;
        int ind1 = (n/2)-1;
        int ind2 = (n/2);
        int count =0;
        int ele1 =-1;
        int ele2 = -1;
        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                if(count==ind1) ele1 = nums1[i];
                if(count==ind2) ele2 = nums1[i];
                count++;
                i++;
            }else{
                if(count==ind2) ele2 = nums2[j];
                if(count==ind1) ele1 = nums2[j];
                count++;
                j++;
            }
        } 
        while(i<n1){
                if(count==ind1) ele1 = nums1[i];
                if(count==ind2) ele2 = nums1[i];
                count++;
                i++;
        }
        while(j<n2){
                if(count==ind2) ele2 = nums2[j];
                if(count==ind1) ele1 = nums2[j];
                count++;
                j++;
        }
        if ((n1+n2)%2 == 1) {
            return (double) ( ele2);
        }
        else{
            return (double) (ele1+ele2) /2.0 ;
        }
    }

};
int main() {
    Solution sol;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double bruteForceMedian = sol.findMedianSortedArrays(nums1, nums2);
    double optimalMedian = sol.OptimalfindMedianSortedArrays(nums1, nums2);

    cout << "Brute Force Median: " << bruteForceMedian << endl;
    cout << "Optimal Median: " << optimalMedian << endl;

    return 0;
}
