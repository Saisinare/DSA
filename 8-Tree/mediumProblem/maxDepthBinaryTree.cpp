
//use depth first search 
//traverse every element and calculate the maximum 

//we can solve it by either DFS traversal which will requires teh extra space complexity O(N)
//or we can just solve it by simple recursion which will requires the 
//Space Complexity of O(H) in worst case O(N)

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(root==nullptr) return 0;
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1+max(leftHeight,rightHeight);
        
    }
};