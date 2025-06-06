#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    //brute force approach with TC n^3
    string longestPalindrome(string s) {
        int maxCount = 0;
        string result="";
        if(s.size()==1) return s;
      for(int i =0;i<s.size()-1;i++){
        
        for(int j = i;j<s.size();j++){
            int start = i;
            int end = j;
            bool isPallindrome = true;
            while(start<=end && start<s.size()){
                if(s[start]!=s[end]){
                    isPallindrome = false;
                    break;
                }
                start++;
                end--;
            }
            if(isPallindrome){
                if(j-i+1>maxCount){
                    maxCount = j-i+1;
                    result = s.substr(i,j-i+1);
                }
            }
        }
      }  
      return result;
    }

    //Optimal force approach with TC n^2
    //if we have 2 centers then the substrin is odd if not then the string is even 
    
    void expand(string &s,int l,int r,int &bestRight,int &bestLeft){
        while(r<s.size() && l>=0 && s[r]==s[l]){
            l--;
            r++;
        }
        l++;
        r--;
        if(r-l+1>bestRight-bestLeft+1){
            bestRight = r;
            bestLeft = l;
        }
    }

    string OptimallongestPalindrome(string s) {
        int bestLeft = 0 ;
        int bestRight = 0;
        for(int i =0;i<s.size();i++){
            expand(s,i,i+1,bestRight,bestLeft);
            expand(s,i,i,bestRight,bestLeft);
        }
        return s.substr(bestLeft,bestRight-bestLeft+1);
    }

};