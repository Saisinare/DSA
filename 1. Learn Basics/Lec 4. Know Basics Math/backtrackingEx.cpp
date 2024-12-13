#include<iostream>
using namespace std;

void printNumbers1toN(int i){
    if(i<1){
        return;
    }
    printNumbers1toN(i-1);
    cout<<i;
}
void printNumbersNto1(int n,int i){
    if(i>n){
        return;
    }
    printNumbersNto1(n,i+1);
    cout<<i;
}
int main(){
    int n = 3;
    printNumbers1toN(n);
    cout<<endl;
    printNumbersNto1(n,1);
    return 0;
}