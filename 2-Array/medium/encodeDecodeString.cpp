#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    string encode(vector<string>& strs) {
        string res = "";
        if (strs.empty()) return "";
        if (strs.size()==1 && strs[0]=="") return "-/";
        int i;
        for(i = 0 ;i<strs.size()-1;i++){
            res+=strs[i];
            res+="-/";
        }
        res+=strs[strs.size()-1];
        return res;
    }

    vector<string> decode(string s) {
        if(s=="") return {};
        if(s=="-/") return {""};
        vector<string> strs;
        string word="";
        for(int i =0;i<s.size();i++){
            word+=s[i];
            if(word.size()>=2 && word[word.size()-1]=='/' && word[word.size()-2]=='-'){
                strs.push_back(word.substr(0,word.size()-2));
                word="";
            }
        }
        strs.push_back(word);
        return strs;
    }
};
