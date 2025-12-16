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