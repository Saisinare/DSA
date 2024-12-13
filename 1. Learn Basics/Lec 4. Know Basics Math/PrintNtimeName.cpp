#include<iostream>
#include<string>
using namespace std;

//TC: O(n)
//SC: O(n)
void printName(int i,int n,string name){
    if(i>n){
        return;
    }
    cout<<name<<endl;
    printName(i+1,n,name);
    i++;
}
int main(){
    printName(1,5,"Sai Sinare");
    return 0;
}