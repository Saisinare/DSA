#include<bits/stdc++.h>
#include<iostream>
using namespace std;

vector<int> rotateArray(vector<int> arr, int k) {
    vector<int> temp;
    k = k%arr.size();

    cout<<k<<"\n";
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        arr[i-k] = arr[i];
    }
    for(int i= arr.size()-k;i<arr.size();i++){
        arr[i] = temp[i-(arr.size()-k)];
    }
    return arr;
}


vector<int> rotateArrayOptimal(vector<int> arr, int k) {
    int n = arr.size();
    reverse(arr.begin(),arr.begin()+k);
    reverse(arr.begin()+k,arr.begin()+n);

    return arr;
}

int main(){
    vector<int> arr = {1,2,3,4};
    vector<int> result = rotateArrayOptimal(arr,1);
    for(int i=0;i<result.size();i++){
        cout<< result[i];
    }
    return -1;
}