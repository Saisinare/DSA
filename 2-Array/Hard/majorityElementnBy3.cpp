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

//optimal approach 
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1=0,c2=0;
        int ele1,ele2;
        int n = nums.size();
        for(int i =0;i<n;i++){
            if(c1==0 && nums[i]!=ele2){
                c1=1;
                ele1 = nums[i];
            }else if(c2==0 && nums[i]!=ele1){
                c2 =1;
                ele2=nums[i];
            }else if(nums[i]==ele1){
                c1++;
            }else if(nums[i]==ele2){
                c2++;
            }else{
                c1--;
                c2--;
            }
        }
        c1 =0;
        c2 =0;
        for(int i =0;i<n;i++){
            if(nums[i]==ele1) c1++;
            if(nums[i]==ele2) c2++;
        }
        vector<int> res;
        if(c1>n/3){
            res.push_back(ele1);
        }
        if(c2>n/3 && ele1!=ele2){
            res.push_back(ele2);
        }
        return res;
    }
};