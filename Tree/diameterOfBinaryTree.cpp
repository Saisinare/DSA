#include<bits/stdc++.h>
using namespace std;

//Brute force 
/*
    T.C. O(N^2)
    S.C. O(1)
 */
class Solution {
public:
    int height(TreeNode* root){
        if(root == nullptr) return 0;
        int leftHeight = height(root->left);w
        int rightHeight = height(root->right);

        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);
        int currentHeight = height(root->left) + height(root->right);
        return max(currentHeight,max(leftDiameter,rightDiameter));
    }
};

//optimal solution 
/*
we will remove the calling of height function in diameter function separately
 */

class Solution {
public:
    int ans = 0;
    int height(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        ans = max(ans,leftHeight+rightHeight);
        return max(leftHeight,rightHeight)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return ans;

    }
};