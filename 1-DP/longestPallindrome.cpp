//  Given a string s, return the longest palindromic substring in s.
/*
    1. create a function which will expand the string from the middle
    2. keep two pointer left and right
    3. if both are equal keep expanding
    4. if not equal break the loop
    5. check if the length of the current palindrome is greater than the best one found so far
    6. if yes update the best left and right indices    
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void expand(string s, int left, int right, int& bestLeft, int& bestRight){
        while(left>= 0 && right <s.size() && s[left] == s[right]){
            left --;
            right ++;
        }
        left++;
        right--;
        if(right - left + 1 > bestRight - bestLeft+1){
            bestLeft = left;
            bestRight = right;
        }
    }
    string longestPalindrome(string s) {
        int bestLeft = 0 ;
        int bestRight = 0;
        for(int i = 0; i<s.size();i++){
            //odd string
            expand(s,i,i+1,bestLeft,bestRight);
            //even string    
            expand(s,i,i,bestLeft,bestRight);       
        }
        return s.substr(bestLeft , bestRight-bestLeft+1);
    }
};

// Time Complexity: O(n^2), where n is the length of the input string.
// Space Complexity: O(1).