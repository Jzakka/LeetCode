class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> rightSide(101, -101);
        queue<TreeNode*> queue;
        queue.push(root);
        int lev = 0;
        while (!queue.empty()) {
            int qLen = queue.size();
            for (int i = 0; i < qLen; i++) {
                auto node = queue.front();
                queue.pop();
                rightSide[lev] = node->val;
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            lev++;
        }
        return vector<int>(rightSide.begin(), find(rightSide.begin(), rightSide.end(),-101));
    }
};