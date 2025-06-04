#include<bits/stdc++.h>
using namespace std;
bool mySort(int a , int b){
    if(a<b){
        return true;
    }else{
        return false;
    }
}

int main(){
    vector<int> arr = {5,4,3,2,1};
    sort(arr.begin(),arr.end(),mySort);
    for(int i = 0;i<arr.size();i++){
        cout<<arr[i]+" ";
    }
    return 0;
}
