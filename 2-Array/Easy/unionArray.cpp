#include<bits/stdc++.h>
using namespace std;

vector < int > sortedArray(vector < int > a, vector < int > b) {
    int i = 0 ;
    int j = 0 ; 
    vector<int> uni;
    int n1 = a.size();
    int n2 = b.size();

    while(i<n1 && j<n2){
        if(a[i] <=b[j]){
            if(uni.size()==0 || uni.back() != a[i]){
                uni.push_back(a[i]);
            }
            i++;
        }else{
            if(uni.size()==0 || uni.back() != b[j]){
                uni.push_back(b[j]);
            }
            j++;
        }
    }

    while(i<n1){
        if(uni.size()==0 || uni.back() != a[i]){
                uni.push_back(a[i]);
            }
            i++;  
    }

    while(j<n2){
        if(uni.size()==0 || uni.back() != b[j]){
                uni.push_back(b[j]);
            }
            j++;  
    }
    return uni;
}

int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {1,2,3,4,5,6,7,8};
    vector<int> unionArray = sortedArray(arr1,arr2);
    for(int i=0;i<unionArray.size();i++){
        cout<<unionArray[i];
    }
}