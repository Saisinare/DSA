#include<iostream>
#include<vector>
using namespace std;
void merge(int arr[],int low,int high,int mid){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left<= mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
            temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
            temp.push_back(arr[right]);
            right++;
    }

    for(int i=low;i<=high;i++){
        arr[i] = temp[i-low];
    }

}
void mergeSort(int arr[],int low,int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,high,mid);
}
int main(){
    int n= 5;
    int arr[n] = {1,6,4,3,2};

    cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }

    mergeSort(arr,0,n-1);

    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
    return 0;
}