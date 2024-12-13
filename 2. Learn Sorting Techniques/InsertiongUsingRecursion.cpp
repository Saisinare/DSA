#include  <iostream>
using namespace std;

void insertionSort(int arr[],int i,int n){
    if(i==n) return;
    int j = i;
    while(j>0 && arr[j-1]>arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1]= temp;

        j--;
    }


    insertionSort(arr,i+1,n);
}

int main(){
 int n= 5;
    int arr[n] = {1,6,4,3,2};

    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    insertionSort(arr,0,n);

    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}