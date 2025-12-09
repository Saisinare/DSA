#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(string &s,int index,vector<vector<string>> &result,vector<string> current){
        if(index==s.size()){
            result.push_back(current);
            return;
        }
        for(int i =index;i<s.size();i++){
            if(isPallindrome(s,index,i)){
                current.push_back(s.substr(index,i-index+1));
                backtrack(s,i+1,result,current);
                current.pop_back();
            }
        }
    }
    bool isPallindrome(string s,int start,int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> current;
        backtrack(s,0,result,current);
        return result;
    }
};