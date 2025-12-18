class Solution {
  public:
    int findCeil(Node* root, int x) {
        Node* curr = root;
        int ans = -1;
        while(curr!=nullptr){
            if(curr->data == x) return x;
            else if(curr->data > x){
                ans = curr->data;
                curr = curr->left;
            }else{
                curr = curr->right;
            }    
        }
        return ans;
    }
};
