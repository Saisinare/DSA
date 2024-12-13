#include <iostream>
using namespace std;

int findSecondLargest(int arr[],int n){
    int largest = arr[0];
    int secondLargest = -1;
    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLargest = largest;
            largest = arr[i];
        }else if(arr[i]>secondLargest && arr[i]<largest){
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

int main(){
    int n = 5;
    int arr[n] = {1,5,2,6,4};
    int secondLargest = findSecondLargest(arr,n);
    cout<<"second largest element in this array is: "<<secondLargest;
    return 0;
}