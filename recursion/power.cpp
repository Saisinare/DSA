#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //O(N Log N)
    double myPow(double x, int n) {
        long double result = 1;
        long long N = n;
        if(N<0){
            N=-N;
            x=1/x;
        }
        while(N>0){
            if(N%2==1){
                result *= x;
                N = N-1;
            }else{
                x = (x*x);
                N = N/2;
            }
        }
        return result;
    }
};

//Recursive approach 
class Solution {
public:
    double recPower(double x,long long N){
        if(N==0) return 1.0;
        if(N%2==1){
            return x*recPower(x,N-1);
        }else{
            return recPower(x*x,N/2);
        }
    }
    double myPow(double x, int n) {
        long double result = 1;
        long long N = n;
        if(N<0){
            N=-N;
            x=1/x;
        }
        
        return recPower(x,N);
    }
};