//better approach

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int> mapp;
        int n = nums.size();
        set<int> sett;
        for(int i=0;i<n;i++){
            mapp[nums[i]]++;
        }
        for(auto it:mapp){
            if(it.second>n/3){
                sett.insert(it.first);
            }
        }
        vector<int> res(sett.begin(),sett.end());
        return res;
    }
};