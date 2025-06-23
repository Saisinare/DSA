class Solution {
public:
    long long MOD = 1e9+7;
    long long power(long long x,long long n){
        if(n == 0) return 1;
        if(n%2==0){
            return power((x*x)%MOD,n/2)%MOD;
        }else{
            return (x*power(x,n-1))%MOD;
        }
    }
    long long myPow(long long x, long long n) {
        return power(x,n);
    }
    int countGoodNumbers(long long n) {
        long long even = (n+1)/2;
        long long odd = n/2;
        long long result = ((myPow(5,even))*(myPow(4,odd)))%MOD;
        return result;
    }
};