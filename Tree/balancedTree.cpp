
class Solution {
public:
    int height(TreeNode* root){
        if(root==nullptr) return true;
        int lH = height(root->left);
        int rH = height(root->right);

        return 1 + max(lH,rH);  
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if(abs(lh-rh)>1) return false;

        bool left  = isBalanced(root->left);
        bool right = isBalanced(root->right);

        return (left && right);

    }
};

//Brute force with TC O^2
