
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


/*
    using morris inorder traversing algorithm 

    need :
        recursive approach for this required recursive stack O(H)
        but morris says we can do it in O(1) extra space 
        in the recursion we have backtracking to go back after visiting left subtree 
        so in iterative approach we should have something which can be used to link back to the root 

        here comes the predecessor node logic  
        a temporary link between the root and its inorder predecessor 

    1. it says that their should be a link between the root and its inorder predecesor 
    inorder predecesor: node which will comes before root in inorder sequence 

    inorder predecsor of root means the right most node of the left most subtree of root 
*/

class Solution {
public:
    TreeNode* findPredecessor(TreeNode* root,TreeNode* curr){
        //if we do not put (root->right != curr) 
        //this loop will continue till infinite so we have to check if we just arrive at the same point 
        while(root->right!=nullptr && root->right != curr){
            root = root->right;
        }
        return root;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* pred = findPredecessor(curr->left,curr);  
                if(pred->right == nullptr){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};