class Solution {
private:
    vector<int> res;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        recursive(root);
        return res;
    }

    void recursive(TreeNode* node){
        if (node == nullptr) {
            return;
        }
        inorderTraversal(node->left);
        res.push_back(node->val);
        inorderTraversal(node->right);
    }
};