#include<iostream>
#include<math.h>
using namespace std;

int findGDC(int n1,int n2){
    int GDC;
    for(int i=1;i<=min(n1,n2);i++){
        if(n1%i==0 && n2%i==0) GDC=i;
    }
    return GDC;
}

int main(){

    int GDC = findGDC(10,20);
    cout<<"GDC is "<<GDC;
    return 0;
}