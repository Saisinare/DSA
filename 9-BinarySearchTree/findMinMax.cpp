/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    int minValue(Node* root) {
        Node* curr =root;
        while(curr->left != nullptr) curr = curr ->left;
        return curr->data;
    }
};