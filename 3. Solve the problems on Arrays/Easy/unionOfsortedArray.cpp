#include<iostream>
#include<vector>
using namespace std;

vector<int> findUnion(vector <int> arr1,vector <int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;
    vector<int> unionArr ;
    while(i<n1 && j<n2){
        
        if(arr1[i] <= arr2[j]){
            if(unionArr.size()==0 || arr1[i]!=unionArr.back()  ){
                unionArr.push_back(arr1[i]);   
            }
            i++;
        }else{
            if(unionArr.size()==0 ||arr2[j]!=unionArr.back()){
                unionArr.push_back(arr2[j]);
                
            }
            j++;
        }

    }

    while(j<n2){
            if(unionArr.size()==0 ||arr2[j]!=unionArr.back()){
                unionArr.push_back(arr2[j]);
                
            }
            j++;
    }

    while(i<n1){
            if(unionArr.size()==0 ||arr1[i]!=unionArr.back()){
                unionArr.push_back(arr1[i]);
            }
            i++;
    }

    return unionArr;
}

int main(){
    vector <int> arr1 = {1,2,3,4,4,5,6,7};
    vector <int> arr2 = {1,1,1,2,3,4,4}; 

    vector <int> unionArr = findUnion(arr1,arr2);

    for(auto it : unionArr){
        cout<<unionArr[it];
    }

    return 0;
}