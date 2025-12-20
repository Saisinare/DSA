/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//using recursive tree traversal which will required extra stack space: 
/*
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int val = root->val;
        if(p->val > val && q->val > val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(p->val < val && q->val<val){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
    }
};
*/
//using a loop : no recursive stack 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while(node != nullptr){
            int val = node->val;
            if(p->val > val && q->val > val){
                node = node -> right ;
            }
            else if(p->val < val && q->val<val){
                node = node -> left;
            }else{
                return node;
            }
        }
        return nullptr;
    }
};