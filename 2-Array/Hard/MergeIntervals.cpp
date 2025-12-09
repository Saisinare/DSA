//brute force will be checking each intervals with others with linear search concept O(N log N + N^2)
//optimal solution O(N log N + N)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        res.push_back(intervals[0]);
        for(int i =1;i<intervals.size();i++){
            vector<int> current = intervals[i];
            vector<int>& last = res.back();
            if(current[0]<=last[1]){
                last[1] = max(current[1],last[1]);
            }else{
                res.push_back(current);
            }
        }
        return res;
    }
};