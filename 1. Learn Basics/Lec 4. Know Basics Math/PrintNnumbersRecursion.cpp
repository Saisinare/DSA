#include<iostream>
using namespace std;

void printNumbers(int i,int n){
    if(i>n) return;
    cout<<i;
    printNumbers(i+1,n);
}

int main(){
    printNumbers(1,5);
    return 0;
}