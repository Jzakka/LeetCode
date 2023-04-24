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
private:
    deque<TreeNode *> leftQ;
    deque<TreeNode *> rightQ;
    const bool LEFT = false;
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        if (root == nullptr) return {};

        vector<vector<int>> res;
        leftQ.push_front(root);
        bool dir = LEFT;
        while (!leftQ.empty() || !rightQ.empty()) {
            int stkLen;
            if(!dir) {
                stkLen = leftQ.size();
            } else {
                stkLen = rightQ.size();
            }

            vector<int> inner;
            for (int i = 0; i < stkLen; i++) {
                if (!dir) { // LEFT
                    auto node = leftQ.front();
                    leftQ.pop_front();
                    inner.push_back(node->val);
                    if (node->left != nullptr) {
                        rightQ.push_back(node->left);
                    }
                    if (node->right != nullptr) {
                        rightQ.push_back(node->right);
                    }
                } else { // RIGHT
                    auto node = rightQ.back();
                    rightQ.pop_back();
                    inner.push_back(node->val);
                    if (node->right != nullptr) {
                        leftQ.push_front(node->right);
                    }
                    if (node->left != nullptr) {
                        leftQ.push_front(node->left);
                    }
                }
            }
            dir = !dir;
            res.push_back(inner);
        }
        return res;
    }
};