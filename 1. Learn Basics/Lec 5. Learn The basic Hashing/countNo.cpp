#include <iostream>
using namespace std;

int main(){

    int n;
    int arr[n];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    //precomputation 
    int hash [13] = {0};
    //in the main the maximum size of an array is upto 10^6 for boolean its 10^7
    // if declare globally it can go upto 10^7 for Int only for boolean its 10^8    
    for(int i=0;i<13;i++){
        hash[arr[i]]++;
    }

    int q;
    cin>>q;
    while(q--){
        int number;
        cin>>number;
        cout<<hash[number]<<endl;
    }
    return 0;
}