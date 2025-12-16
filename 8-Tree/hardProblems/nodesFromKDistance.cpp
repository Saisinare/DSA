#include <bits/stdc++.h>
using namespace std;    

  struct Node {
      int data;
      Node *left;
      Node *right;
      Node() : data(0), left(nullptr), right(nullptr) {}
      Node(int x) : data(x), left(nullptr), right(nullptr) {}
      Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
  };
class Solution {

  public:
    Node* markParent(Node* root,unordered_map<Node*,Node*>& mapp,int target){
        queue<Node*> q;
        q.push(root);
        Node* targetNode = nullptr;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            if(curr->data == target) {
                targetNode = curr;
            }
            if(curr->left) {
                mapp[curr->left] =curr;
                q.push(curr->left);
            }
            if(curr->right) {
                mapp[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return targetNode;
    }
    vector<int> KDistanceNodes(Node* root, int target, int k) {
        if(root == nullptr) return {};
        unordered_map<Node*,Node*> mapp; //child->parent
        Node* targetNode = markParent(root,mapp,target);
        unordered_map<Node*,bool> visited;
        if(!targetNode) return {};
        queue<Node*> q;
        
        q.push(targetNode);
        visited[targetNode]=true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;

            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true; 
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;  
                }
                if(mapp[curr] && !visited[mapp[curr]]){
                    q.push(mapp[curr]);
                    visited[mapp[curr]] = true;
                }
            }
            dist++;
        }
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->data);
            q.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};