#include<iostream>
using namespace std;
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
    int fibo = fibonacci(5);
    cout<<fibo;
    return 0;
}