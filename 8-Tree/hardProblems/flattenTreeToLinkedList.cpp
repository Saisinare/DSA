/*
class Solution {
public:

    TreeNode* findPredecessor(TreeNode* root,TreeNode* curr){
        //if we do not put (root->right != curr) 
        //this loop will continue till infinite so we have to check if we just arrive at the same point 
        while(root->right!=nullptr && root->right != curr){
            root = root->right;
        }
        return root;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        TreeNode* curr = root;
        vector<int> ans;
        while(curr!=nullptr){
            if(curr->left == nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else {
                TreeNode* pred = findPredecessor(curr->left,curr);  
                if(pred->right == nullptr){
                    ans.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    pred->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }

    void flatten(TreeNode* root) {
        vector<int> preorder = preorderTraversal(root);
        TreeNode* curr = root;
        if(root){
        root -> left = nullptr;
        root->right = nullptr;

        }
        for(int i = 1 ;i<preorder.size();i++){
            TreeNode* node = new TreeNode(preorder[i]);
            curr->right = node;
            curr = curr -> right;
        }
    }
};
*/

class Solution {
public:

    TreeNode* findPredecessor(TreeNode* root,TreeNode* curr){
        //if we do not put (root->right != curr) 
        //this loop will continue till infinite so we have to check if we just arrive at the same point 
        while(root->right!=nullptr && root->right != curr){
            root = root->right;
        }
        return root;
    }

    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr!=nullptr){
            if(curr->left != nullptr){
                TreeNode* pred = findPredecessor(curr->left,curr);
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = nullptr;
            }
            curr = curr -> right;
        }

    }
};