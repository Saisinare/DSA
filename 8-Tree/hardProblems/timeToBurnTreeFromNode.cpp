//use the radical traversing technique to find the answer 
//radical means we traverse to each sided possible (left, right, and parent)
//as the adjucent nodes burn at every minute we increase the counter of minutes whenever we traverse all the adjucent nodes 
//now we can easily travel to the left and right but for parent we don't have pointer so we have to firstly sort that 
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
    TreeNode* markParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parentMap,int start){
        queue<TreeNode*> q;
        TreeNode* startNode = nullptr;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            if(front->val == start) startNode = front;
            q.pop();
            if(front->left){ 
                parentMap[front->left] = front; 
                q.push(front->left);
            }
            if(front->right){ 
                parentMap[front->right] = front; 
                q.push(front->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        if(root==nullptr) return 0;
        //using unordered_map may increase some runtime constant as in the best case it has complexity of average case for insert update read is O(1) and worst case is O(1)
        unordered_map<TreeNode*,TreeNode*> parentMap;
        TreeNode* startNode = markParents(root,parentMap,start);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        visited[startNode] = true; 
        q.push(startNode);
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){
                TreeNode* front = q.front();
                q.pop();
                //if left is not burned yet burn it 
                if(front->left && !visited[front->left]){
                    visited[front->left] = true;
                    q.push(front->left);
                }
                //if right is not burned yet burn it 
                if(front->right && !visited[front->right]){
                    visited[front->right] = true;
                    q.push(front->right);
                }
                //if parent is not burned yet burn it 
                if(parentMap[front] && !visited[parentMap[front]]){
                    visited[parentMap[front]] = true;
                    q.push(parentMap[front]);
                }
            }
            time++;
        }
        return time-1;
    }
};
//TC: O(N) as we are traversing in every direction till the end of tree 
//SC: O(N) worst case for recursive Stack O(N) + map O(N) = 2n 
//for average case for map O(1) + O(n) for recursive stack 
