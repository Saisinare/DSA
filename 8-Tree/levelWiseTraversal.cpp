// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(w), where w is the maximum width of the tree (max number of nodes at any level).
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Time Complexity: O(n), where n is the number of nodes in the tree.
// Space Complexity: O(w), where w is the maximum width of the tree (max number of nodes at any level).
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr ) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
            }
            ans.push_back(level);
        }
        return ans;
    }
};