#include<bits/stdc++.h>
using namespace std ; 

class Solution {
public:
    bool rotateString(string s, string goal) {
        string doubleString = goal + goal ;
        if(s.size() !=goal.size()) return false;
        for(int i = 0 ; i<=doubleString.size() - goal.size();i++){
            bool match = true;
            for(int j = 0 ;j<s.size();j++){
                if(doubleString[j+i]!=s[j]){
                    match  = false;
                    break;
                }
            }
            if(match==true){
                return true;
            }
        }
        return false;
    }
};
