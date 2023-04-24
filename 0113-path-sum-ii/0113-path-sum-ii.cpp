class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        vector<int> comb;
        DFS(res, comb, root, targetSum, 0);
        return res;
    }

    void DFS(vector<vector<int>> &res, vector<int> &comb, TreeNode *node, int targetSum, int sum) {
        sum += node->val;
        comb.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            if (targetSum == sum) {
                res.push_back(comb);    
            }
            comb.pop_back();
            return;
        }
        if (node->left != nullptr) {
            DFS(res, comb, node->left, targetSum, sum);
        }
        if (node->right != nullptr) {
            DFS(res, comb, node->right, targetSum, sum);
        }
        comb.pop_back();
    }
};