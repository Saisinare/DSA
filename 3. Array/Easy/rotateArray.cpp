#include<vector>
#include<iostream>
using namespace std;
void rotateArrayBrute(vector<int> &arr){
    int i = 0;
    int temp = arr[0];

    for(i=1;i<arr.size();i++){
        arr[i-1] = arr[i];
    }
    arr[i-1] = temp;
}

int main(){
    vector<int> arr  = {5,1,2,0,6,7};
    rotateArrayBrute(arr);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i];
    }
}