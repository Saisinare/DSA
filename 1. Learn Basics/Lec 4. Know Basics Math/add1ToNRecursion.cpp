#include<iostream>
using namespace std;
//using parametrised function 
void add1toN(int i,int sum){
    if(i<1){
        cout<<sum;
        return;
    }
    add1toN(i-1,sum+i);
}
//using non-permetrised 
int add(int n){
    if(n==0){
        return 0;
    }
    return n+add(n-1);
}
int main(){
    add1toN(5,0);
    cout<<"\n using non paramterized funtion "<<endl;
    cout<<add(5);
    return 0;
}