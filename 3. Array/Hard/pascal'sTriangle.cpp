#include<bits/stdc++.h>
using namespace std;
int findElement(int row,int col){
    int res = 1;
    for(int i=0;i<col;i++){
        res = res *(row-i);
        res = res/(i+1);
    }
    return res;
}
int main(){
    cout<<findElement(4,2);
    return 0;
}