

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
/*
    approach 1: 
        1. Search for the node with value = key 
        2. Delete node
            1. if it has the left node then this root is replaced by its left 
                now if root has right child its right side will goes to the right most node of the new root 
                if not then just keep it as it is 
        3. if root does not have left then directly root is replaced by the right side 

    approach 2: 
        1. find node with key val 
        2. find its inorder sucessor (samllest value of right subtree) as when you delete the root node it can be replaced by it inorder sucessor
        3. now delete thing inorder sucessor 
*/
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        
        if(key > root->val){
            root->right = deleteNode(root->right,key);
        }else if(key<root->val){
            root->left = deleteNode(root->left,key);
        }else{
            if(root->left == nullptr){
                return root->right;
            }
            else if(root->right == nullptr){
                return root->left;
            }else{
                int mini = findMin(root->right);
                root->val = mini;
                root->right = deleteNode(root->right,root->val);
            }
        }
        return root;

    }

    int findMin(TreeNode* root){
        TreeNode* node = root;
        int mini = root->val;
        while(node->left != nullptr){
            mini = node->left->val;
            node = node->left; 
        }
        return mini;
    }
};

//TC :  TC for finding node in worst case is O(H)
//      TC for deleting node in worst case is o(H)
//      overall O(H) in worst case if the tree is skewed H=N then TC = O(N)
//      in average case O(log n) if tree is normal/balanced
 
//SC : O(H) recursive stack if tree is skewed then O(N)