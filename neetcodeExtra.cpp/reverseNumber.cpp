#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//brute force 
    int reverse(int x) {
        int reverse = 0 ;
        int temp = x ;
        while(temp){
            if(reverse*10>INT_MAX){
                reverse = 0;
                break;
            }
            if(reverse*10<INT_MIN){
                reverse = 0;
                break;
            }
            reverse = (reverse*10)+(temp%10);
            temp = temp / 10;
        }
        return reverse;
    }
//optimal approach 
    int reverse(int x) {
        int reverse = 0 ;
        int temp = x ;
        while(temp){
            if(reverse>INT_MAX/10){
                reverse = 0;
                break;
            }
            if(reverse<INT_MIN/10){
                reverse = 0;
                break;
            }
            reverse = (reverse*10)+(temp%10);
            temp = temp / 10;
        }
        return reverse;
    }
};