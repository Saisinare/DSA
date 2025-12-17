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
    TreeNode* findPredecessor(TreeNode* root,TreeNode* curr){
        //if we do not put (root->right != curr) 
        //this loop will continue till infinite so we have to check if we just arrive at the same point 
        while(root->right!=nullptr && root->right != curr){
            root = root->right;
        }
        return root;
    }
    vector<int> preorderTraversal(TreeNode* root) {
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
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};