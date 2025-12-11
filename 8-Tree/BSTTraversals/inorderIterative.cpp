/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
 Start at root and set node = root.

Go to the leftmost node:

Keep pushing nodes onto the stack.

Move node = node->left until node becomes NULL.

Pop from stack:

This is the next node to visit.

Add its value to ans.

Move to right subtree:

node = poppedNode->right

Repeat steps 2–4 while:

stack is not empty OR

node is not NULL.
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return {};
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* node = root;
        while(!st.empty() || node!=nullptr ){
            while(node!=nullptr){
                st.push(node);
                node = node->left;
            }
            TreeNode* top = st.top();
            st.pop();
            ans.push_back(top->val);
            node = top -> right;
        }
        return ans;
    }
};

//TC : O(N)
/*
SC : O(H) for 
best: (when tree is balanced): height is (log n) 
worst: (when tree is skewed): height is (N)
*/