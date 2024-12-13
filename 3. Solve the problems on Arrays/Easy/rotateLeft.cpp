#include <iostream>
using namespace std;
//reove duplicate elements from the sorted array
void rotateElement(int arr[],int n){
    int first = arr[0];
    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1]; 
    }
    arr[n-1] = first;

}

int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    cout<<"array before rotating "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    rotateElement(arr,n);
    cout<<"array after rotating "<<endl;

    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}