//brute force: traverse all of the nodes 
/*
    TC: O(N)
    SC: O(H) in worst case it is O(N)
*/

//optimal solution: 
/*
    TC: O(log(n)*log(n))
    SC: O(H) 
*/
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
    int findRightHeight(TreeNode* root){
        int height = 0 ;
        while(root!=nullptr){
            height ++;
            root = root->right;
        }
        return height;
    }
    int findLeftHeight(TreeNode* root){
        int height = 0 ;
        while(root!=nullptr){
            height ++;
            root = root->left;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        int left = findLeftHeight(root);
        int right = findRightHeight(root);

        if(left == right) return (1<<left) -1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};