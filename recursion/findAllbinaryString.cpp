// User function Template for C++
#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void backtrack(int num,vector<string> &result,string current){
        if(current.size()==num){
            result.push_back(current);
            return;
        }
        backtrack(num,result,current+"0");
        if(current[current.size()-1]!='1'){
        backtrack(num,result,current+"1");
        }

    }
    vector<string> generateBinaryStrings(int num) {
        vector<string> result;
        backtrack(num,result,"");
        return result;
    }
};