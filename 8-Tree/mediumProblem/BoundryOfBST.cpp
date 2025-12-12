class Solution {
  public:
    bool isLeaf(Node *root){
        if(root->left == nullptr && root->right == nullptr) {
            return true;
        }
        return false;
    }
    void addLeftNodes(Node *root,vector<int>&ans){
        Node* cur = root;
        while(cur!=nullptr){
            if(!isLeaf(cur)) ans.push_back(cur->data);
            if(cur->left !=nullptr) cur = cur->left; 
            else if(cur->right!=nullptr) cur=cur->right;
            //don't forget to break this loop 
            else break;
        }
    }
    void addRightNodes(Node *root,vector<int>&ans){
        stack<int> st;
        Node* cur = root;
        while(cur!=nullptr){
            if(!isLeaf(cur)) st.push(cur->data);
            if(cur->right !=nullptr) cur = cur->right; 
            else if(cur->left!=nullptr) cur=cur->left;
            //also this
            else break;
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    void addLeafs(Node *root,vector<int>&ans){
        if(root==nullptr) return;
        if(isLeaf(root)){ 
            ans.push_back(root->data);
            return;
        }
        addLeafs(root->left,ans);
        addLeafs(root->right,ans);
    }
    
    vector<int> boundaryTraversal(Node *root) {
        if(root==nullptr) return{};
        if(isLeaf(root)) return {root->data};
        vector<int> ans;
        ans.push_back(root->data);
        addLeftNodes(root->left,ans);
        addLeafs(root->left,ans);
        addLeafs(root->right,ans);
        addRightNodes(root->right,ans);
        return ans;
    }
};