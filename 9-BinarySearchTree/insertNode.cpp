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
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* curr = root;
        TreeNode* node = new TreeNode(val);
        if(root == nullptr) return node;
        while(curr!=nullptr){
            if(curr->val < val){
                if (!curr->right){
                    node->right = curr->right;
                    curr->right = node;
                    return root;
                }
                curr = curr ->right;
            }else{
                if(!curr->left){
                    node->left = curr->left;
                    curr->left = node;
                    return root;
                }
                curr = curr ->left;
            }
        }
        return nullptr;
    }
};