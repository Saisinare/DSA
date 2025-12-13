//brute force approach using vertical traversal
//TC: O(NlogN) SC: O(N)
/*
#include<bits/stdc++.h>
using namespace std;

void verticalTraverse(TreeNode<int>* root,map<int,map<int,vector<int>>>& mapp,int verticalLevel,int horizontalLevel){
        if(root == nullptr) return ;
        mapp[horizontalLevel][verticalLevel].push_back(root->data);
        verticalTraverse(root->left,mapp,verticalLevel+1,horizontalLevel-1);
        verticalTraverse(root->right,mapp,verticalLevel+1,horizontalLevel+1);
}
vector<vector<int>> verticalTraversal(TreeNode<int>* root) {
        if(root == nullptr) return {};
        map<int,map<int,vector<int>>> mapp;
        verticalTraverse(root,mapp,0,0);
        vector<vector<int>> ans;
        for(auto it:mapp){
            vector<int> row;
            for(auto i : it.second){
                row.insert(row.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(row);
        }
        return ans;
    }

vector<int> getTopView(TreeNode<int> *root){
    stack<pair<int,int>> st;
    vector<int> ans;
    vector<vector<int>> arr = verticalTraversal(root);
    for(auto i:arr){
        ans.push_back(i[0]);
    }
    return ans;
}
*/

//optimal approach using level order traversal
//TC: O(NlogN) SC: O(N)
#include<bits/stdc++.h>
using namespace std;

vector<int> getTopView(TreeNode<int> *root){

    //traverse through all of the nodes using queue 
    //maintain a mapp with the vertical level index and node 
    //only insert new node when we do not have any node at that index 
    //convert this into array and return 

    if(root == nullptr) return {};
    map<int,int> mapp;
    queue<pair<int,TreeNode<int>*>> q;
    q.push({0,root});

    while(!q.empty()){
        pair<int,TreeNode<int>*> front = q.front();
        int idx = front.first;
        q.pop();
        if(mapp.find(idx) == mapp.end()){
            mapp[idx] = front.second->data; 
        }
        if(front.second->left != nullptr) q.push({idx-1,front.second->left});
        if(front.second->right !=nullptr) q.push({idx+1,front.second->right});
    }

    vector<int> ans;
    for(auto it:mapp){
        ans.push_back(it.second);
    }
    return ans;
}
