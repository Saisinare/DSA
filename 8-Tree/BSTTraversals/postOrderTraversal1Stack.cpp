

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        vector<int> ans ;
        while(!st.empty() || curr!=nullptr){
            if(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode* rightChild = st.top()->right;
                if(rightChild==nullptr){
                    TreeNode* top = st.top();
                    st.pop();
                    ans.push_back(top->val);
                    while(!st.empty() && top == st.top()->right){
                        top = st.top();
                        st.pop();
                        ans.push_back(top->val);
                    }
                }else{
                    curr = rightChild;
                }
            }
        }
        return ans;
    }
};