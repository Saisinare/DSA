//same as the house robber one but does the last house is the neibour of the first one 
//we are not allow to rob both the first and last house

class Solution {
public:
    int performRob(vector<int>& nums){
        int rob1 = 0 , rob2 = 0;
        for(int n : nums){
            int maxSum = max(n+rob1 , rob2);
            rob1 = rob2 ;
            rob2 = maxSum;
        }
        return rob2;
    }
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        int n = nums.size();
        vector<int> firstArr(nums.begin(),nums.begin()+n-1);
        int first = performRob(firstArr);
        vector<int> lastArr(nums.begin()+1,nums.begin()+n);
        int last = performRob(lastArr);
        
        return max(first,last);
    }
};

//O(N) T.C
//O(1) S.C
