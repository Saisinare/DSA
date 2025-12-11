/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<vector<int>> getTreeTraversal(TreeNode *root){
    if(root==nullptr) return {};
    vector<int> pre,post,inorder;
    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if(it.second==1){
            it.second++;
            st.push(it);
            pre.push_back(it.first->data);
            if(it.first->left!=nullptr){
                st.push({it.first->left,1});
            }
        }else if(it.second == 2){
            it.second++;
            st.push(it);
            inorder.push_back(it.first->data);
            if(it.first->right!=nullptr){
                st.push({it.first->right,1});
            }
        }else{
            post.push_back(it.first->data);
        }
    }
    return {inorder,pre,post};
}