//brute force solution 
    /*
        1. find the next smaller and previouse smaller element for every element 
        2. now loop through array and return the maximum area = heights[i]*preSmaller[i]-nextSmaller[i];
    */
#include<bits/stdc++.h>
using namespace std;   
class Solution {
public:
    vector<int> nextSmaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size(),nums.size());
        for(int i =nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty() && nums[st.top()]<nums[i]){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmaller(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size(),-1);
        for(int i =0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(!st.empty() && nums[st.top()]<nums[i]){
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse = nextSmaller(heights);
        vector<int> pse = prevSmaller(heights);

        int maxi = INT_MIN;
        for(int i =0;i<heights.size();i++){
            int area = heights[i] * (nse[i]-pse[i]-1);
            maxi = max(maxi,area);
        }
        return maxi;
    }
};

//T.c (O(5N))
//T.c (O(4N))



//Optimal Solution 
    /*
        We scan bars left to right, and keep a stack of indices of bars in increasing height order.

When we see a bar shorter than the stack’s top, that means the taller bar at top can’t extend further right.

We pop that bar, and calculate its largest rectangle using:

height = popped bar’s height

width = distance between current index and new stack top.

Keep updating the maximum area found so far.

At the end (dummy 0 bar), we pop everything left in stack to ensure all bars are processed.
    */
class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans (n,-1);
        int maxi = 0 ;
        stack<int> st;
        for(int i =0;i<=n;i++){
            int currentHeight = (i==n)?0:heights[i];
            while(!st.empty() && heights[st.top()]>= currentHeight){
                int tp = st.top();
                st.pop();
                int hi = heights[tp];

                int wi;
                if(st.empty()){
                    wi = i; 
                }else{
                    wi = (i  - st.top()-1);
                }
                maxi = max(maxi,hi*wi);
            }
            st.push(i);
        }
        return maxi;
    }
};