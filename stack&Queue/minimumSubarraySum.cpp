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



//Optimal approach 
    /*
    1. find the previous smaller element 
    2. find the next smaller element 
    3. multiply both with num [i]
    5. add it to the sum 
    reutrn sum 
    */
class Solution {
public:
    const int MOD = 1e9 + 7;

    // Previous Smaller Element: distance to left
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return left;
    }

    // Next Smaller Element: distance to right
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        return right;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);
        long long sum = 0 , mod = 1e9+7;
        for(int i =0;i<arr.size();i++){
            long long left = pse[i];
            long long right = nse[i];
            long long val = arr[i];

            long long contribute = ((left * right) % MOD * val) % MOD;
            sum = (sum + contribute) % MOD;
        }
        return sum;
    }
};

//O(n)
//O(n)



//Optimal Solution
    /*
        1. Find minimum and maximum element sum using monotonic stack 
        2. return maximum - minimum 

        T.C.: O(5N)+O(5N) = O(10N) = O(N) 
        S.C.: O(N);
    */
class Solution {
public:


        vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return left;
    }

    // Next Smaller Element: distance to right
    vector<int> nextSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        return right;
    }

    long long sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = nextSmaller(arr);
        vector<int> pse = prevSmaller(arr);
        long long sum = 0 , mod = 1e9+7;
        for(int i =0;i<arr.size();i++){
            long long left = pse[i];
            long long right = nse[i];
            long long val = arr[i];

            long long contribute = ((left * right) * val);
            sum = (sum + contribute);
        }
        return sum;
    }



        vector<int> prevGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            left[i] = st.empty() ? i + 1 : i - st.top();
            st.push(i);
        }
        return left;
    }

    // Next Smaller Element: distance to right
    vector<int> nextGreater(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            right[i] = st.empty() ? n - i : st.top() - i;
            st.push(i);
        }
        return right;
    }

    long long sumSubarrayMax(vector<int>& arr) {
        vector<int> nse = nextGreater(arr);
        vector<int> pse = prevGreater(arr);
        long long sum = 0 , mod = 1e9+7;
        for(int i =0;i<arr.size();i++){
            long long left = pse[i];
            long long right = nse[i];
            long long val = arr[i];

            long long contribute = ((left * right) * val);
            sum = (sum + contribute);
        }
        return sum;
    }
    

    long long subArrayRanges(vector<int>& nums) {
        return (long long)sumSubarrayMax(nums) - sumSubarrayMins(nums); 
    }
};

//O(N^2) T.C
//O(1) S.C.