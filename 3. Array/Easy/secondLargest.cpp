#include<vector>
#include<iostream>
using namespace std;
int findSecondLargest(vector<int> arr){
    int large = -1;
    int secLarge = -1;
    for(int i =0 ;i<arr.size();i++){
        if(arr[i]>large){
            secLarge = large;
            large = arr[i];
        }else if(arr[i] < large && arr[i] > secLarge ){
            secLarge = arr[i];
        }
    }
    return secLarge;
}

int main(){
    vector<int> arr  = {5,1,2,0,6,7};
    int secLarge = findSecondLargest(arr);
    cout<<" "<<secLarge;

}