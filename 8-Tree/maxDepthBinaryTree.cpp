
//use depth first search 
//traverse every element and calculate the maximum 

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root==nullptr) return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1+max(leftHeight,rightHeight);
        
    }
};