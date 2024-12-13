#include<iostream>
using namespace std;

int isArmstrong(int n) {
    int num = n;
    int armstrong = 0;;
    while (n > 0) {
        int temp = n % 10;
        armstrong += (temp*temp*temp);
        n /= 10;
    }
    cout<<armstrong;
    if(armstrong == num){
        return true;
    }else{
        return false;
    }
}

int main(){
    if(isArmstrong(370)) cout<<" number is armstrong";
    else cout<<"not a armstrong";
    return 0;
}