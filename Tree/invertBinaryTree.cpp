//swap the right and left node of root 
//repeat this until the end of tree using recursion 

// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(h), where h is the height of the tree (recursion stack).
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return root;

        //swap the left and right nodes 
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        //recursively call inertTree to left and right 
        invertTree(root->right);
        invertTree(root->left);

        return root;
    }
};