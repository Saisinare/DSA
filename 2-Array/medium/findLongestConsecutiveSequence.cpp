#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> temp;
        if (nums.size() == 0) return 0;
        for(int i =0;i<nums.size();i++){
            temp.insert(nums[i]);
        }
        int longest = 1;
        for(auto it:temp){
            if(temp.find(it-1)==temp.end()){
                int x = it;
                int count = 1;
                while(temp.find(x+1)!=temp.end()){
                    x = x+1;
                    count ++ ;
                }
                longest = max(count,longest);
            }
        }
        return longest;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    
    int result = solution.longestConsecutive(nums);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}

