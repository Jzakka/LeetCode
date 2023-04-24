class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int acc = 0;
        int res = 0;
        preOrder(root, acc, res);
        return res;
    }

    void preOrder(TreeNode* node, int acc, int& res){
        acc += node->val;
        if (node->left == nullptr && node->right == nullptr) {
            res += acc;
            return;
        }

        if (node->left != nullptr) {
            preOrder(node->left, acc*10, res);
        }
        if (node->right != nullptr) {
            preOrder(node->right, acc*10, res);
        }
    }
};