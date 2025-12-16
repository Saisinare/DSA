/*
    preorder tells what is the root of the tree as the first element of preorder traversal is always going to be the root of tree 
    once we find the root of tree all the elements before the root in the inorder traversal array is going to be in the left subtree 
    same for the right subtree 
*/
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
    TreeNode* splitTree(vector<int>& preorder,map<int,int>& inorderIndexMap,int rootIndex,int left,int right){
        TreeNode* root = new TreeNode(preorder[rootIndex]);
        int mid =  inorderIndexMap[root->val];
        if(mid>left){
            root->left = splitTree(preorder,inorderIndexMap,rootIndex+1,left,mid-1);
        }
        if(mid<right){
            root->right = splitTree(preorder,inorderIndexMap,rootIndex+mid-left+1,mid+1,right);
            //rootIndex+1+(mid-left)
            //mid-left is the number of nodes in the left subtree
            //+1 for the root node
            //so we reach the start of the right subtree in the preorder array
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorderIndexMap;
        for(int i =0;i<inorder.size();i++){
            inorderIndexMap[inorder[i]] = i;
        }
        return splitTree(preorder,inorderIndexMap,0,0,inorder.size()-1);
    }
};