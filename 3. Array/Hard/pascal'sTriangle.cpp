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

//brute force code for finding the nth row in triangle 
class Solution {
public:
    int findElement(int row, int col){
        long long ans = 1;
        for(int i =0;i<col;i++){
            ans *= row-i;
            ans /= i+1; 
        }
        return ans;
    }
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        for(int c = 0;c<=rowIndex;c++){
            ans.push_back(findElement(rowIndex,c));
        }
        return ans;
    }
};

// O(row ^2)

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long num = 1;
        rowIndex++;
        ans.push_back(num);
        for(int c = 1;c<rowIndex;c++){
            num *= (rowIndex-c);
            num /= c;
            ans.push_back(num);
        }
        return ans;
    }
};
