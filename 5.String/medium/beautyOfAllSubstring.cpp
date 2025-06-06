#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
       int sum = 0 ;

        unordered_map<char,int> mapp;
       for(int i =0;i<s.size();i++){ //O(n)
            for(int j =i;j<s.size();j++){ //O(n)
                mapp[s[j]]++;
                int maxFrequency = 0;
                int leastFrequency = s.size();

                for(auto &it:mapp){ //O(log k ) k can be at most 26 as the letters in the english 
                    leastFrequency = min(leastFrequency,it.second);
                    maxFrequency = max(maxFrequency,it.second);
                }

                sum += maxFrequency-leastFrequency;
            }
                mapp.clear();
       }
       return sum;
    }
};

//O(n^2) as the constant of log k where k is max 26 is constant so the time complexity is O(n^2)