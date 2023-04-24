class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        queue<TreeNode*> Q;
        Q.push(root);
        int depth = 1;
        while (!Q.empty()) {
            int qLen = Q.size();

            for (int i = 0; i < qLen; i++) {
                auto node = Q.front();
                Q.pop();
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }else{
                    if (node->left != nullptr) {
                        Q.push(node->left);
                    }
                    if (node->right != nullptr) {
                        Q.push(node->right);
                    }    
                }
            }
            depth++;
        }
        return depth-1;
    }
};