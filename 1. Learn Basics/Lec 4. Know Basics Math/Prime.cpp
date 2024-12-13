#include<iostream>
#include<math.h>
using namespace std;
//TC: O(srrt(n))
void isPrime(int n){
    int count =0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
                count ++;
                if(n/i!=i){
                    count++;
                }
        }
    }
    if(count ==2){
        cout<<"number is prime";
    }else{
        cout<<"not a prime number";
    }
}
int main(){
    int n = 11;
    isPrime(n);
    return 0;
}