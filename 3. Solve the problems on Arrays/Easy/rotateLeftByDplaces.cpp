#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//reove duplicate elements from the sorted array
//TC is O(D+1)
//SC is O(D)
void rotateElement(int arr[],int n, int d){
    d = n % d;
    int temp[d];

    for(int i=0;i<d;i++){
        temp[i] = arr[i];
    }

    for(int i=d;i<n;i++){
        arr[i-d] = arr[i];
    }

    for(int i=n-d;i<n;i++){
        arr[i] = temp[i-(n-d)];
    }

}
//TC is O(2n) 
//SC is O(1)
void optimizeRotation(int arr[],int n,int d){
    reverse(arr,arr+d);
    reverse(arr+d,arr+n);
    reverse(arr,arr+n);
}
int main(){
    int n = 5;
    int arr[] = {1,2,3,4,5};
    cout<<"array before rotating "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    optimizeRotation(arr,n,3);
    cout<<"array after rotating "<<" ";

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}