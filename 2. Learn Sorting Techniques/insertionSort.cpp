#include<iostream>

using namespace std;

int main(){
    int n =6;
    int arr[n] = {4,1,2,9,5,0};
    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    for(int i=0;i<n;i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            int temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        } 
    }

    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}