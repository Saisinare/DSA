#include <vector>
#include <algorithm>    
using namespace std;    

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return intervals;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i = 1;i<n;i++){
            vector<int> &prev = ans.back();
            if(prev[1]>=intervals[i][0]){
                prev[1] = max(prev[1],intervals[i][1]); 
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};