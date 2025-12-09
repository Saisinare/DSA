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



//optimal solution of m*n
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for(string &str: strs){
            vector<int> count(26,0);
            for(char &c: str){
                count[c-'a']++;
            }
            string key;
            for(int i:count){
                key = key + to_string(i)+'#';
            }
            ans[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto &it: ans){
            res.push_back(it.second);
        }
        return res;
    }
};