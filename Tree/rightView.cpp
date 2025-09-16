//direct optimal solution 
/*
    1. use Reverse PreOrder Traversal 
    2. just at each level add the nodes in mapp who are the first in their level 
*/
class Solution {
public:
//use the reverse pre order traversal 
    void RPO(TreeNode* root,int level,map<int,TreeNode*> & mapp){
        if(root==nullptr) return;

        if(mapp.find(level)==mapp.end()) mapp[level] = root;
        RPO(root->right,level+1,mapp);
        RPO(root->left,level+1,mapp);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,TreeNode*> mapp;
        RPO(root,0,mapp);
        vector<int> ans;
        for(auto & it:mapp){
            ans.push_back(it.second->val);
        }
        return ans;
    }
};