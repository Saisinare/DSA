class Solution {
  public:
    bool traverse(Node *root){
        if(root == nullptr) return true;
        if(root->left == nullptr && root->right == nullptr) return true;
        if(root->left && root->right){
            if(root->data != root->left->data + root->right->data) return false;
        } 
        else if(root->left){
            if(root->data!=root->left->data) return false; 
        }
        else if(root->right){
            if(root->data != root->right->data) return false;
        }
        bool left = traverse(root->left);
        bool right = traverse(root->right);
        
        if(!left || !right ) return false;
        return true;
        
    }
    bool isSumProperty(Node *root) {
        return traverse(root);
    }
};