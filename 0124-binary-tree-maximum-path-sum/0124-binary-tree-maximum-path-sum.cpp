class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int maxPathSum = -4000;

        recursive(root, maxPathSum);

        return maxPathSum;
    }

    int recursive(TreeNode *node, int &pathSum) {
        if (node == nullptr) {
            return 0;
        }
        int leftPathSum = recursive(node->left, pathSum);
        int rightPathSum = recursive(node->right, pathSum);

        int candidate = max(leftPathSum + node->val,
                            max(node->val + rightPathSum, node->val));
        pathSum = max(candidate, max(pathSum, leftPathSum + node->val + rightPathSum));
        return candidate;
    }
};