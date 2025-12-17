
#include <bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    TreeNode* splitTree(vector<int>& postorder,unordered_map<int,int>& inorderMap,int idx, int left, int right){
        TreeNode* root = new TreeNode(postorder[idx]);
        int mid = inorderMap[root->val];

        if(mid<right){
            root->right = splitTree(postorder,inorderMap,idx-1,mid+1,right);  
        } 
        if(mid>left){
            root->left = splitTree(postorder,inorderMap,idx-(right-mid)-1,left,mid-1);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inorderMap;
        for(int i =0;i<inorder.size();i++){
            inorderMap[inorder[i]] = i;
        }
        return splitTree(postorder,inorderMap,postorder.size()-1,0,inorderMap.size()-1);
    }
};