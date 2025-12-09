class Codec {
public:
    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    void preorder(TreeNode* root, string& s) {
        if (!root) {
            s += "#,";
            return;
        }
        s += to_string(root->val) + ",";
        preorder(root->left, s);
        preorder(root->right, s);
    }

    TreeNode* deserializeHelper(const vector<string>& nodes, int& idx) {
        if (idx >= nodes.size() || nodes[idx] == "#") {
            idx++;
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(nodes[idx++]));
        root->left = deserializeHelper(nodes, idx);
        root->right = deserializeHelper(nodes, idx);
        return root;
    }

    TreeNode* deserialize(string data) {
        vector<string> nodes;
        string temp;
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        int idx = 0;
        return deserializeHelper(nodes, idx);
    }
};
