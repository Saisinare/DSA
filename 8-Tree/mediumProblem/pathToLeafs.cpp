    class Solution {
    public:
        void traverse(TreeNode *root,vector<string>& ans,string path){
            if(root->left == nullptr && root->right == nullptr){
                ans.push_back(path);
                return;
            }
            if(root->left) traverse(root->left,ans,path+"->"+to_string(root->left->val));
            if(root->right) traverse(root->right,ans,path+"->"+to_string(root->right->val));
        }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            if(root == nullptr) return {};
            traverse(root, ans,""+to_string(root->val));
            return ans;
        }
    };