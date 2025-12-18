/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int floor(Node* root, int x) {
        Node* curr = root;
        int ans = -1;
        while(curr!=nullptr){
            if(curr->data == x) return x;
            else if(curr->data < x){
                ans = curr->data;
                curr = curr->right;
            }else{
                curr = curr->left;
            }    
        }
        return ans;
        
    }
};