#include <bits/stdc++.h>
using namespace std;
//optimal Solution 
void backtrack(vector<int> &vec,vector<vector<int>> &ans,int index){
    if(index==vec.size()){
        ans.push_back(vec);
        return;
    }    
    for(int i =index;i<vec.size();i++){
        swap(vec[index],vec[i]);
        backtrack(vec,ans,index+1);
        swap(vec[index],vec[i]);
    }
} 
vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>> ans;
    backtrack(vec,ans,0);
    return ans;
}
/*
    TC:- O(N!*N);
    SC:- O(N) just recursion call stack depth;
 */
//brute force 
#include <bits/stdc++.h>
void backtrack(vector<int> &vec,vector<vector<int>> &ans,vector<bool>& used,vector<int>& current){
    if(current.size()==vec.size()){
        ans.push_back(current);
        return;
    } 
    for(int i =0;i<vec.size();i++){
        if(used[i]) continue;

        current.push_back(vec[i]);
        used[i] = true;
        backtrack(vec,ans,used,current);
        current.pop_back(); 
        used[i] = false;
    }
} 
vector<vector<int>> permutations(vector<int> &vec, int size) {
    vector<vector<int>> ans;
    vector<int> current;
    vector<bool> used (size,false);
    backtrack(vec,ans,used,current);
    return ans;
}

/* 
    T.C. :- (N!*N)
    S.C. :- O(N!*N)
*/