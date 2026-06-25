class Solution {
public:
    bool isValid(TreeNode* node, long long low, long long high) {
        if (node == nullptr)
            return true;

        if (node->val <= low || node->val >= high)
            return false;

        return isValid(node->left, low, node->val) &&
               isValid(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};