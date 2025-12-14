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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<long long,TreeNode*>> q ;
        q.push({0,root});
        int maxi = 0 ;
        while(!q.empty()){
            int mini = q.front().first;
            int first,last;
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* node = q.front().second;
                //for overflow safety normalized all index level wise and variable should be long long otherwise it can overflow if high is greater than 31  
                long long curId = q.front().first - mini;
                q.pop();
                if(i==0) first = curId;
                if(i==size-1) last = curId;
                if(node->left != nullptr){
                    q.push({curId*2+1,node->left});
                }   
                if(node->right!=nullptr){
                    q.push({curId*2+2,node->right});
                }
            }
            maxi = max(maxi,last-first + 1);
        }
        return maxi;
    }
};