#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums,int index,vector<int>& ans,vector<vector<int>> &subset){
        if(index==nums.size()){
            subset.push_back(ans);
            return;
        }
        //include the element 
        ans.push_back(nums[index]);
        backtrack(nums,index+1,ans,subset);

        ans.pop_back();

        //exclude the element 
        backtrack(nums,index+1,ans,subset);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ans;
        backtrack(nums,0,ans,subset);
        return subset;
    }
};