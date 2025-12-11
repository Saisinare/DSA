
 

 
#include <bits/stdc++.h>    
using namespace std;
class Solution {
public:
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        stack<TreeNode*> st1,st2;
        TreeNode* node = root;
        st1.push(root);
        while(!st1.empty()){
            TreeNode* top = st1.top();
            st2.push(top);
            st1.pop();
            if(top->left!=nullptr){
                st1.push(top->left);
            }
            if(top->right!=nullptr){
                st1.push(top->right);
            }
        }
        vector<int> ans;
        while(!st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};