class Solution {
public:
    void traverse(TreeNode* node, vector<int>& ans) {
        if (node == nullptr) return;

        traverse(node->left, ans);
        ans.push_back(node->val);
        traverse(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};