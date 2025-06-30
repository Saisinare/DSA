#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(vector<int>& nums,int index,vector<vector<int>> &result,vector<int> current){
        result.push_back(current);
        for(int i =index;i<nums.size();i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
                current.push_back(nums[i]);
                backtrack(nums,i+1,result,current);
                current.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums,0,result,current);
        return result;
    }
};