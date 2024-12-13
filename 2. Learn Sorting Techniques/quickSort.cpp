#include<iostream>
#include<vector>
using namespace std;

//TC O(n log n)
//SC (1)

int sort(int arr[],int low,int high){

    int pivot = arr[low];
    int i = low;
    int j= high; 

    while(i<j){
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        while(arr[j]>pivot && j>=low){
            j--;
        }

        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    }
int temp = arr[low];
arr[low] = arr[j];
arr[j] = temp;

return j;

}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int partIndex = sort(arr,low,high);
        quickSort(arr,low,partIndex-1);
        quickSort(arr,partIndex+1,high);
    }
}

int main(){
    int n= 5;
    int arr[n] = {1,6,4,3,2};

    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    quickSort(arr,0,n-1);
    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}