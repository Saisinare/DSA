#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mapp = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000},
        };
        int result = 0 ;
        int i ;
        for(i =0;i<s.size();i++){
            if(mapp[s[i]]<mapp[s[i+1]]) result-=mapp[s[i]];
            else result+=mapp[s[i]];
        }
        return result;
    }
};
