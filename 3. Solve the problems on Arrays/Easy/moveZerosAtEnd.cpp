#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void moveZeros(int arr[],int n){ //TC O(2n) SC O(n)
    vector <int> temp;
    for(int i=0;i<n;i++){
        //TC O(n)
        if(arr[i] !=0){
            temp.push_back(arr[i]);
        }
    } 
    for(int i=0;i<temp.size();i++){
        //TC O(x)
        arr[i] = temp[i];
    }
    for(int i=temp.size()-1;i<n;i++){
        //TC O(n-x)
        arr[i] = 0;
    }
}
void optiMizedZeros(int arr[],int n){
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    if(j==-1) return;
    for(int i=j+1;i<n;i++){
        if(arr[i]!=0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    } 

}
int main(){
    int n= 8;
    int arr[] = {1,2,3,4,0,0,3,5};
     cout<<"array before sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    optiMizedZeros(arr,n);
    cout<<endl;
    cout<<"array after sorting ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}