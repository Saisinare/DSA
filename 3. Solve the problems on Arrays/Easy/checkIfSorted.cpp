#include <iostream>
using namespace std;

void checkIsSorted(int arr[],int n){
    int isSorted = 0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            cout<<"array is not sorted";
            isSorted = 1;
            break;
        }
    }
    if(isSorted == 0){
        cout<<"array is sorted";
    }
}

int main(){
    int n = 5;
    int arr[n] = {1,2,3,7,6};
    checkIsSorted(arr,n);
    return 0;
}