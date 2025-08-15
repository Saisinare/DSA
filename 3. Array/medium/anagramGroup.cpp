//brute force solution with nlogn * m Time complexity 
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> group;
        for(string st : strs){
            string key = st;
            sort(key.begin(),key.end());
            group[key].push_back(st);
        }
        vector<vector<string>> result;
        for(auto &it: group){
            result.push_back(it.second);
        }
        return result;
    }
};