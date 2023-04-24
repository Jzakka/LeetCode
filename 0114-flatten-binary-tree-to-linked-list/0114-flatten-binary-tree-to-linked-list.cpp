class Solution {
public:
    void flatten(TreeNode *root) {
        if(root== nullptr) return;
        preOrder(root);
    }

    pair<TreeNode *, TreeNode *> preOrder(TreeNode *node) {
        TreeNode *left = node;
        TreeNode *right = node;
        pair<TreeNode *, TreeNode *> leftSubTree = {nullptr, nullptr};
        pair<TreeNode *, TreeNode *> rightSubTree = {nullptr, nullptr};
        if (node->left == nullptr && node->right == nullptr) {
            return {left, right};
        }
        else if (node->left == nullptr) {
            rightSubTree = preOrder(node->right);
            right->right = rightSubTree.first;
            right = rightSubTree.second;
            return {left, right};
        } else if (node->right == nullptr) {
            leftSubTree = preOrder(node->left);
            left->left = nullptr;
            right->right = leftSubTree.first;
            right = leftSubTree.second;
            return {left, right};
        }
        leftSubTree = preOrder(node->left);
        left->left = nullptr;
        rightSubTree = preOrder(node->right);
        right->right = leftSubTree.first;
        leftSubTree.second->right = rightSubTree.first;
        right = rightSubTree.second;

        return {left, right};
    }
};