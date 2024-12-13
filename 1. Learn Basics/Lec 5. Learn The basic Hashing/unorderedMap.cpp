#include<iostream>
#include<unordered_map>
using namespace std;
//TC for av and best are O(1) worst is O(n) so first use unordered map and if it fail then use ordered map  
//key can be only individual element it cannot be a pair in the unordered map 
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute 
    unordered_map<int,int> mapp;
    for(int i=0;i<n;i++){
        mapp[arr[i]]++;
    }
    int q;
    cin >>q;

    while(q--){
        int number ;
        cin>>number;

        //fetch 
        cout<<mapp[number];
    }
    return 0;

}