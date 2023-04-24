class Solution {
public:
    bool isBalanced(TreeNode *root) {
        return root == nullptr
               || isBalanced(root->left)
               && isBalanced(root->right)
               && (abs(height(root->left) - height(root->right)) < 2);
    }

    int height(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        return max(height(node->left), height(node->right)) + 1;
    }
};