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

 /*
    1. Maintain the upper bound initially it is INT_MAX
    2. when we go to the left side from root the upper bound will be the root->val
    3. when right upper bound will be up previous UB 
    4. return null when the index is out of bound or root->val is > UB 
 */
class Solution {
public:
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0 ;
        return builtTree(preorder,i,INT_MAX);
    }
    TreeNode* builtTree(vector<int>& preorder,int& i,int ub){
        if(i>preorder.size()-1 || preorder[i] > ub) return nullptr;
        TreeNode* node = new TreeNode(preorder[i]);
        i++;
        node->left = builtTree(preorder,i,node->val);
        node->right = builtTree(preorder,i,ub);
        return node;
    }
};