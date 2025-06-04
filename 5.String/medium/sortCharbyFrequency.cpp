#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string OptimalfrequencySort(string s) {
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
        string frequencySort(string s) {
        unordered_map<char,int> mapp;
        for(int i =0;i<s.size();i++){
            mapp[s[i]]++;
        }
        //map to vector 
        vector<pair<char,int>> myVec;
        for(auto it:mapp){
            myVec.push_back({it.first,it.second});
        }
        //sort the vector
        sort(myVec.begin(),myVec.end(),[](pair<char,int> &a,pair<char,int> &b){
            return a.second > b.second; 
        });
        //insert into the result;
        string result = "";
        for(pair<char,int> &it:myVec){
            while(it.second>0){
                result += it.first;
                it.second--;
            }
        }
        return result;
    }
};