class Solution {
private:
    queue<TreeNode*> Q;
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> res;
        Q.push(root);

        while (!Q.empty()) {
            int stkLen = Q.size();
            vector<int> inner;
            for (int i = 0; i < stkLen; i++) {
                auto node = Q.front();
                Q.pop();
                inner.push_back(node->val);
                if (node->left != nullptr) {
                    Q.push(node->left);
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                }
            }
            res.push_back(inner);
        }
        return res;
    }
};