#include <iostream>
#include <math.h>
using namespace std;

void countDefault(int n){
    //time complexity: log10(n) because no. of operations are dependent on division
    int count =0;
    while(n>0){
        n = n/10;
        count++;
    }
    cout<<count;
}
void countBylog(int n){
    int count = log10(n)+1;
    cout<<count;
}
int main(){
    countDefault(16445);
    countBylog(165213);
    return 0;
}