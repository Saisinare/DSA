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

//IMP: maintaining a proper indexing for the row and col are very very  important or when the collison happens nodes with same col and row then the ordering issue will happen 
//for solution of that sort everything first col wise vector then insert it 
class Solution {
public:
    void verticalTraverse(TreeNode* root,map<int,map<int,vector<int>>>& mapp,int verticalLevel,int horizontalLevel){
        if(root == nullptr) return ;
        mapp[horizontalLevel][verticalLevel].push_back(root->val);
        verticalTraverse(root->left,mapp,verticalLevel+1,horizontalLevel-1);
        verticalTraverse(root->right,mapp,verticalLevel+1,horizontalLevel+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == nullptr) return {};
        map<int,map<int,vector<int>>> mapp;
        verticalTraverse(root,mapp,0,0);
        vector<vector<int>> ans;
        for(auto it:mapp){
            vector<int> row;
            for(auto i : it.second){
                sort(i.second.begin(),i.second.end());
                row.insert(row.end(),i.second.begin(),i.second.end());
            }
            ans.push_back(row);
        }
        return ans;
    }
};

/*
TC: O(N)
SC: O(N) (worst case for recursive stack) + O(N) (for map data structure)
*/