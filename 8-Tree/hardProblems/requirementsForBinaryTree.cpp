class Solution {
  public:
    bool isPossible(int a, int b) {
        // Unique tree is possible only if inorder (2) is present
        if(a==b) return false;
        return (a == 2 || b == 2);
    }
};