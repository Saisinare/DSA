
class Solution {
public:
//travers through the tree 
//store it into the vector 
//sort the vector 
//return the kth element 
    void traverse(vector<int>& arr,TreeNode* root){
        if(root==nullptr) return;
        arr.push_back(root->val);
        traverse(arr,root->left);
        traverse(arr,root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> final ;
        traverse(final,root);
        sort(final.begin(),final.end());
        return final[k-1];
    }
};