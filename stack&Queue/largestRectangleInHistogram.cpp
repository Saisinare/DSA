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