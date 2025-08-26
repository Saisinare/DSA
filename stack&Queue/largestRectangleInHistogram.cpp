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
        Keep a stack to store indices of bars in increasing height order.

        Go through each bar one by one.

        If the current bar is smaller than the stack’s top bar, pop from stack (the taller bar ends here).

        For the popped bar → calculate area = height × width, update maxi.

        After processing, push the current index in the stack and continue.
    */

class Solution {
public:

    int largestRectangleArea(vector<int>& heights) {
        int maxi = 0 ;
        stack<int> st;
        int n = heights.size();
        for(int i =0;i<=n;i++){
            int currentHeight = (i==n)? 0:heights[i];
            while(!st.empty() && heights[st.top()]>= currentHeight){
                int tp = st.top();
                st.pop();
                int height = heights[tp];
                int width = 0 ;
                if(st.empty()){
                    width = i;
                }else{
                    width = i - st.top() - 1;
                }
                maxi = max(maxi,height*width);
            }
            st.push(i);
        }
        return maxi;
    }
};