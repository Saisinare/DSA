#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool BruteisAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s.size()!=t.size()) return false;
        for(int i = 0;i<s.size();i++){
            if(s[i]!=t[i]) return false;
        }
        return true;
    }
    bool OptimalisAnagram(string s, string t) {
        vector<int> count(26,0);
        if(s.size()!=t.size()) return false;
        for(int i =0;i<s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        for(int i = 0;i<count.size();i++){
            if(count[i]!=0) return false;
        }
        return true;
    }
};