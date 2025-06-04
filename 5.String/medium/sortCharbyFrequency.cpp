#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mapp ;
        string result = "";
        vector<pair<int,char>> resultVec;
        for(int i =0 ;i<s.size();i++){
            mapp[s[i]]++;
        }
        for(auto it:mapp){
            resultVec.push_back({it.second,it.first});
        }
        sort(resultVec.rbegin(),resultVec.rend());
        for(auto it:resultVec){
            result+=string(it.first,it.second);
        }
        return result;
    }
};