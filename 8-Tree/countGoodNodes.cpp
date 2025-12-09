// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree (recursion stack).
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
    //root , maxi, count
    int findCount(TreeNode* root,int maxi){
        if(root==nullptr) return 0;
        int good = 0 ;
        if(root->val>=maxi){
            maxi = root->val;
            good = 1;
        } 
        int left = findCount(root->left,maxi);
        int right = findCount(root->right,maxi);
        return good + right + left;
    }
    int goodNodes(TreeNode* root) {
        return findCount(root,INT_MIN);
    }
};