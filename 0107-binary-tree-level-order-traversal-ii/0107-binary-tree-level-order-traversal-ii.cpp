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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> Q;
        stack<vector<int>> stk;

        Q.push(root);
        while (!Q.empty()) {
            int QLen = Q.size();

            vector<int> temp;
            for (int i = 0; i < QLen; i++) {
                auto node = Q.front();
                Q.pop();
                temp.push_back(node->val);
                if(node->left!= nullptr) Q.push(node->left);
                if(node->right!= nullptr) Q.push(node->right);
            }
            stk.push(temp);
        }

        vector<vector<int>> res;
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }
};