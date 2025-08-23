#include<bits/stdc++.h>
using namespace std;
//you have given the array you have to find all of the possible subarray's minimum
    /*
        1. brute force
            generate all of the subarrays 
            find and return the minimum    
        
        
    */ 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long mod = 1e9+7;
        long long sum = 0 ;
        for(int i =0;i<arr.size();i++){
            int mini = INT_MAX;
            for(int j =i;j<arr.size();j++){
                mini = min(mini,arr[j]);
                sum = (sum+mini)%mod;
            }
        }
        return (int)sum;     
    }
};

//T.C. O(N square)
//S.C. O(1)
