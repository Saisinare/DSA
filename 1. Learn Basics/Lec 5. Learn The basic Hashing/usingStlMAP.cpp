#include<iostream>
#include<map>
using namespace std;
//TC of map is in all cases the fetching and storing takes log(n)
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //precompute 
    map<int,int> mapp;
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