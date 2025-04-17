#include<bits/stdc++.h>
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

int main(){
    vector<int> arr = {1,2,3,4};
    vector<int> result = rotateArray(arr,1);
    for(int i=0;i<result.size();i++){
        cout<< result[i];
    }
    return -1;
}