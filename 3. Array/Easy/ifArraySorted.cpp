#include<vector>
#include<iostream>
using namespace std;
int isSorted(int n, vector<int> a) {
    for(int i = 1;i<n;i++){
        if(a[i]>=a[i-1]){

        }else{
            return 0;
        }
    }
    return 1;
}

int main(){
    vector<int> arr  = {5,1,2,0,6,7};
    int isSort = isSorted(arr.size(),arr);
    if(isSort == 1){

    cout<<"Array is sorted ";
    }else{

    cout<<" "<<"array is not sorted";
    }

}