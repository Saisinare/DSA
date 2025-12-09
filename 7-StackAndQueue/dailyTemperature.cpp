//use next element logic 
    /*
        Q. their are n numbers of days temparature are given in array you have to return the array which should contain the distance between the next greater element and the current element if not found then it should hav 0

        --> 1. use the next greater element logic 
            2. store the index rather than element in the stack 
            3. add nextGreaterIndex - currentIndex in array with respective place 
            4. return it   
    */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> st;
        vector<int> ans(n,0);
        for(int i =n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(!st.empty() && temperatures[st.top()]>temperatures[i]){
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};
