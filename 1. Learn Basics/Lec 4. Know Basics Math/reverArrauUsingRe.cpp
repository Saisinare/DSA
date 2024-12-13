#include<iostream>
using namespace std;

void reverse(int arr[],int i,int n){
    if(i>=n-i-1){
        return;
    }
    int temp = arr[n-i-1];
    arr[n-i-1] = arr[i];
    arr[i] = temp; 
}

int main(){
    int arr[] = {1,2,3};
    cout<<"Original: "<<endl;
    for(int item: arr){
        cout<<item<<endl;
    }
    
    reverse(arr,0,3);

    cout<<"after reversing : "<<endl;
    for(int item: arr){
        cout<<item<<endl;
    }

    return 0;
}