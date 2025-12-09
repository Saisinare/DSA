

// Time Complexity: O(n) where n is the number of nodes in the tree.
// Space Complexity: O(n) for storing node values in a vector or recursion stack.
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


// optimal approach
// we can do the inorder traversal of the tree and keep a count of the nodes
//recursively go to the left subtree



class Solution {
public:
    //inorder traverse through the BST 
    //keep the count increasing at each level 
    //return kth node  
    int result = -1;
    int count = 0;
    
    void traverse(TreeNode* root, int k){
        if(root==nullptr || result!=-1) return;
        traverse(root->left,k);

        count++;
        if(count==k){
            result = root->val;
            return;
        }

        traverse(root->right,k);
    }
    int kthSmallest(TreeNode* root,int k) {
        traverse(root,k);
        return result;
    }
};