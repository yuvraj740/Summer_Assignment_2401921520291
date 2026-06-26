class Codec {
public:

    // Serialize
    void preorder(TreeNode* root, string &s) {
        if (root == nullptr) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        preorder(root->left, s);
        preorder(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        preorder(root, s);
        return s;
    }

    // Deserialize
    TreeNode* build(queue<string> &q) {
        string cur = q.front();
        q.pop();

        if (cur == "#")
            return nullptr;

        TreeNode* root = new TreeNode(stoi(cur));

        root->left = build(q);
        root->right = build(q);

        return root;
    }

    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;

        for (char c : data) {
            if (c == ',') {
                q.push(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }

        return build(q);
    }
};