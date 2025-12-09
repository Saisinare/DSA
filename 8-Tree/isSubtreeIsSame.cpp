
// Time Complexity: O(m * n) where m and n are the number of nodes in root and subRoot respectively.
// Space Complexity: O(h) where h is the height of the tree due to recursion stack.
// Time Complexity: O(m * n) where m and n are the number of nodes in root and subRoot respectively.
// Space Complexity: O(h) where h is the height of the tree due to recursion stack.
class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(root==nullptr && subRoot==nullptr) return true;
        if(root==nullptr || subRoot==nullptr) return false;

        if(root->val != subRoot -> val) return false;
        bool left = isSame(root->left,subRoot->left);
        bool right = isSame(root->right,subRoot->right);
        return left && right;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr || subRoot==nullptr) return root==subRoot;
        if(root->val == subRoot->val && isSame(root,subRoot))return true;

        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};