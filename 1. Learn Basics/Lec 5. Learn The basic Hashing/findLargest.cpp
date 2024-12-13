#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    unordered_map<int,int> mapp;
    int largest = 0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        mapp[arr[i]]++;
        if(mapp[arr[i]]>mapp[largest]){
            largest = arr[i];
        }
    }
    cout<<"element which has largest count: "<<largest<<" having count: "<<mapp[largest];
    int q;
    cin>>q;

    return 0;
}