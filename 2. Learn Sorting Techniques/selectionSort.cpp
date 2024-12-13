#include<iostream>

using namespace std;

int main(){
    int n=5;
    int arr[] = {1,6,2,4,3};
    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    for(int i=0;i<n;i++){
        int mini = i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i]= temp; 
    }
    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}