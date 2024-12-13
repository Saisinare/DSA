#include <iostream>
using namespace std;

void bubbleSort(int arr[],int low,int high,int i){
    int sorted = 0;
    if(low>=high){
        return;
    }
    if(arr[i]>arr[i+1]){
        int temp = arr[i];
        arr[i]= arr[i+1];
        arr[i+1] = temp;
        sorted = 1;
    }
    i++;
    if(i>=high){
        high--;
        i = low;
        if(sorted == 0) return;
    }
    bubbleSort(arr,low,high,i);
}
int main(){
        int n= 5;
    int arr[n] = {1,6,4,3,2};

    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    bubbleSort(arr,0,n-1,0);

    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}