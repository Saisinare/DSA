#include<bits/stdc++.h>
using namespace std;

int findStudentCount(vector<int>& arr,int n,int pages){
    int currentPages = 0;
    int studentCount = 1;
    for(int i =0;i<n;i++){
        if(arr[i]+currentPages<=pages){
            currentPages+= arr[i];
        }else{
            studentCount++;
            currentPages = arr[i];
        }
    }
    return studentCount;    
}

int findPages(vector<int>& arr, int n, int m) {
    if(m>n) return -1;
        int maxi = INT_MIN;
    int sum = 0;
    for(int i =0;i<arr.size();i++){
        sum += arr[i];
        if(arr[i]>maxi){
            maxi = arr[i];
        }
    }

    int low = maxi;
    int high = sum;

    while(low<=high){
        int mid = low + (high-low)/2;
        int studentCount = findStudentCount(arr,n,mid);
        if(studentCount>m) low = mid+1;
        else high = mid-1;
    }
    return low;
}
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int result = findPages(nums,nums.size(),k);
        return result;
    }
};


int main() {
    vector<int> nums = {7, 2, 5, 10, 8};  // Example array
    int k = 2;  // Number of subarrays (students)

    Solution sol;
    int result = sol.splitArray(nums, k);
    cout << "Minimum largest sum after split: " << result << endl;

    return 0;
}
