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
class BSTIterator {
public:
    stack<TreeNode*> st;
    bool reverse = false;
    BSTIterator(TreeNode* root,bool rev) {
        reverse = rev;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushAll(TreeNode* root){
        TreeNode* node = root;
        while(node != nullptr){
            st.push(node);
            if(!reverse){
                node = node -> left;
            }else{
                node = node -> right;
            }
        }
    }
};
class Solution {
public:  
    bool findTarget(TreeNode* root, int k) {
        BSTIterator* l = new BSTIterator(root,false);
        BSTIterator* r = new BSTIterator(root,true);

        int i = l->next();
        int j = r->next();

        while(i<j){
            int sum = i + j;
            if(sum>k){
                j = r->next();
            }else if(sum<k){
                i = l->next();
            }else{
                return true;
            }
        }
        return false;
    }
};

/*
TC: O(N)
SC: O(2H)
*/