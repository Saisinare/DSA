#include <bits/stdc++.h>
using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        //as intitially we are inserting the root in the q so we are already have done the left to right traversal so the next traversal is going to be opposite traversal
        bool leftToRight = false;
        while(!q.empty()){
            int size = q.size();
            vector<int> row(size);
            for(int i = 0 ;i<size;i++){
                int index = (leftToRight)? i : (size - 1 - i);
                TreeNode* front = q.front();
                q.pop();
                row[index] = front->val;
                if(front->right != nullptr){
                    q.push(front->right);
                }
                if(front->left != nullptr){
                    q.push(front->left);
                }
            }
            leftToRight = !leftToRight;
            ans.push_back(row);
        }
        return ans;
    }
};