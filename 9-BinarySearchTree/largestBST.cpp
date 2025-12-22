#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:

    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    //{size,min,max}
    vector<int> findLargestWithMinMax(Node *root){
        if(root==nullptr) return {0,INT_MAX,INT_MIN};
        
        auto left = findLargestWithMinMax(root->left);
        auto right = findLargestWithMinMax(root->right);
        
        //left[max] && right[min]
        if(left[2] < root->data && right[1] > root->data){
            return {1 + left[0] + right[0],
                    min(left[1],root->data),
                    max(right[2],root->data)
                    };
        }
        return {max(right[0],left[0]),INT_MIN,INT_MAX};
    }
    int largestBst(Node *root) {
        return findLargestWithMinMax(root)[0];
    }
};