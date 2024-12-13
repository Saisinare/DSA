#include<iostream>
#include<math.h>
using namespace std;

//TC: O(n)
int main(){
    int n = 10;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
                cout<<i<<endl;
                if(n/i!=i){
                    cout<<n/i<<endl;
                }
        }
    }
    return 0;
}