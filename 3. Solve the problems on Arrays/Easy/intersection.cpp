#include<iostream>
#include<vector>
using namespace std;

vector<int> findIntersection(vector <int> arr1,vector <int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    int i=0;
    int j=0;

    vector<int> intersection ;

    while(i<n1 && i<n2){
        if(arr1[i]<arr2[j]){
           i++;
        }else if(arr1[i]>arr2[j]){
            j++;
        }else{
            intersection.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    return intersection;
}

int main(){
    vector <int> arr1 = {1,2,3,4,4,5,6,7};
    vector <int> arr2 = {1,1,1,2,3,4,4}; 

    vector <int> intersection = findIntersection(arr1,arr2);

    for(int i=0;i<intersection.size();i++){
        cout<<intersection[i]<<" ";
    }

    return 0;
}