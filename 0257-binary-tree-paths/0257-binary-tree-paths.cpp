class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        string history;
        vector<string> result;
        dfs(result, history, root);
        return result;
    }

    void dfs(vector<string> &res, string history, TreeNode *node){
        history += to_string(node->val);

        if (!node->left && !node->right) {
            res.push_back(history);
            return;
        }
        if (node->left) {
            dfs(res, history + "->", node->left);
        }
        if (node->right) {
            dfs(res, history + "->", node->right);
        }
    }
};