class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        bfsInvert(root);
        return root;
    }

    void bfsInvert(TreeNode* root){
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int qLen = Q.size();

            for (int i = 0; i < qLen; i++) {
                auto node = Q.front();
                Q.pop();

                if (node->left) {
                    Q.push(node->left);
                }
                if (node->right) {
                    Q.push(node->right);
                }
                swap(node->left, node->right);
            }
        }
    }
};