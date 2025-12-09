// preorder : gives guarantee where root exists 
// inorder : when we find the preorder node in the inorder sequence every node to the left is part of left subtree and every right element is the right subtree  
//valid inorder: values are from the left to the i-1 and i+1 to right 
//we have to pass the left and the right boundry in the rcusrive call 
//we are going to require the function which will return the index of the element in the inorder sequence 

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &preIdx, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        int inIdx = search(inorder, inStart, inEnd, root->val);

        root->left = helper(preorder, inorder, preIdx, inStart, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, inEnd);

        return root;
    }

    int search(vector<int>& inorder, int inStart, int inEnd, int item) {
        for (int i = inStart; i <= inEnd; i++) {  // fixed condition
            if (inorder[i] == item) return i;
        }
        return -1;
    }
};
