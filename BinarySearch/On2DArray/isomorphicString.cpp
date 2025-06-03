#include<bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool BruteisIsomorphic(string s, string t) {
        map<char,char> mapString;
        int i = 0 ;
        while(i<s.size() && i<t.size()){
            auto it = mapString.find(s[i]);
            for(auto iterator : mapString){
                if(iterator.second == t[i] && iterator.first != s[i])
                    return false;
            }
            if(it==mapString.end()){
                mapString[s[i]] = t[i];
            }else if(it->first == s[i] && it->second!=t[i]){
                return false;
            }
            i++;
        }
        return true;
    }
    bool OptimalIsMorpohic(string s,string t){
        unordered_map<char,char> mapp;
        unordered_set<char> sett;
        for(int i =0;i<s.size();i++){
            if(!mapp.count(s[i])){
                if(sett.count(t[i])) return false;
                mapp[s[i]] = t[i];
                sett.insert(t[i]);
            }else{
                if(mapp[s[i]]!=t[i]) return false;
            }
        }
        return true;
    }
};