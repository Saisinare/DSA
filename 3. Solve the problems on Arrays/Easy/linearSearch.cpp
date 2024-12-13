#include<iostream>

using namespace std;

int main(){
    int n =6;
    int arr[n] = {4,1,2,9,5,0};
    int item ;
    cin>>item;
    for(int i=0;i<n;i++){
        if( arr[i] == item){
            cout<<item<<" found at the position"<<i<<endl;
        }
    }

    return 0;
}