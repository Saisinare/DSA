#include <iostream>
using namespace std;
//reove duplicate elements from the sorted array
int removeDuplicate(int arr[],int n){
    int j=0;
    int i=0;
    while(j<n){
        if(arr[i] != arr[j]){
            i++;
            arr[i] = arr[j];
        }
        j++;
    }
    return i+1;
}

int main(){
    int arr[] = {1,2,2,3,4,4};
    int newIndex = removeDuplicate(arr,6);
    for(int i=0;i<newIndex;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}