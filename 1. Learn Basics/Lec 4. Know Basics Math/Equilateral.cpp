#include<iostream>
using namespace std;
//TC: O(log(min(n1,n2)))
void findEquilateral(int n1,int n2){
    while(n1!=0 && n2!=0){
        if(n1>n2) {n1 = n1%n2;}
        else {n2 = n2%n1;}
    }
    if(n1==0) cout<<"GCD is "<<n2;
    else cout<<"GCD is "<<n1; 
}
int main(){
    findEquilateral(10,20);
    return 0;
}