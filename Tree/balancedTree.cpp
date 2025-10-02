// Time Complexity: O(n), where n is the number of nodes in the tree (for the optimal solution).
// Space Complexity: O(h), where h is the height of the tree (recursion stack).

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

class Solution {
public:
    int height(TreeNode* root){
        if(root==nullptr) return true;
        int lH = height(root->left);
        int rH = height(root->right);
        if(lH == -1 || rH == -1) return -1;
        if(abs(lH-rH)>1) return -1;
        return 1 + max(lH,rH);  
    }
    bool isBalanced(TreeNode* root) {
        if (root==nullptr) return true;

        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 || rh==-1) return false;
        if(abs(lh-rh)>1) return false;

        return true;

    }
};

//optimal solution of O(N)
