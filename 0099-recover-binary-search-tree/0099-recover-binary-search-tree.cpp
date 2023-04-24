class Solution {
private:
    TreeNode* prev;
public:
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT32_MIN);
        inOrderLeft(root);
        prev = new TreeNode(INT32_MAX);
        inOrderRight(root);
    }

    void inOrderLeft(TreeNode* root){
        if (root->left != nullptr) {
            inOrderLeft(root->left);
        }
        if (prev->val > root->val) {
            swap(prev->val, root->val);
        }
        prev = root;
        if (root->right != nullptr) {
            inOrderLeft(root->right);
        }
    }
    void inOrderRight(TreeNode* root){
        if (root->right != nullptr) {
            inOrderRight(root->right);
        }
        if (prev->val < root->val) {
            swap(prev->val, root->val);
        }
        prev = root;
        if (root->left != nullptr) {
            inOrderRight(root->left);
        }
    }
};