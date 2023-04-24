/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return DFS(root, targetSum, root->val);
    }

    bool DFS(TreeNode* node, int targetSum, int sum){
        if (node->left == nullptr && node->right == nullptr) {
            return targetSum == sum;
        }
        bool left, right;
        left = right = false;
        if (node->left != nullptr) {
            left = DFS(node->left, targetSum, sum + node->left->val);
        }
        if (node->right != nullptr) {
            right = DFS(node->right, targetSum, sum + node->right->val);
        }
        return right | left;
    }
};