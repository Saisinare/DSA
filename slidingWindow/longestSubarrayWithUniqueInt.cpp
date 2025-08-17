class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int count = 0 ;
        for(int i =0;i<nums.size();i++){
            set<int> sett ;
            for(int j = i;j<nums.size();j++){
                sett.insert(nums[j]);
                if(sett.size()==k) count++;
                else if(sett.size()>k) break;
            }
        }
        return count;
    }
};

//using O(N^2) T.C and O(N) S.C.