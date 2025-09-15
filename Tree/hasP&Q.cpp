//optimal solution 
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root; 
        if(root==p || root==q) return root; 
        /*
        their are two cases 1. the p and q are below and up to each other 2. p and q are on the different branches 
        in both cases we have to return the first occurence of either p or q cause their even if their is the matching q below the root it does-n't matter as its ancestor will be firstly finded p or q 
        and in the second case the next p or q is not going to be their  
        */
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        //now when we check if left and right side has the p or q their are 4 conditions 
        /*
            1. both are valid then return root 
            2. either right side has p or q then return who is valid 
            3. left side has p or q 

        */
        if(leftAns && rightAns) return root;
        else if(rightAns != nullptr) return rightAns;
        else return leftAns;
    }
};

//TC O(N)
//SC O(N)