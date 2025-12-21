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
    TreeNode* n1=nullptr;
    TreeNode* n2=nullptr;
    TreeNode* n3=nullptr;
    TreeNode* prev=nullptr;

    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        if(prev!=nullptr && (root->val < prev->val)){
            if(!n1){
                n1 = prev;
                n2 = root;
            }else if(!n3){
                n3 = root;
            }
        }

        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        if(root==nullptr) return;
        n1 = n2 = n3 = nullptr;
        TreeNode dummy(INT_MIN);
        prev = &dummy;
        inorder(root);
        if(n1 && n3) swap(n1->val,n3->val);
        else swap(n1->val,n2->val);
    }
};