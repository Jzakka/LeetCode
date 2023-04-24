class BSTIterator {
private:
    vector<int> vec;
    int i = 0;

    void inOrder(TreeNode* root){
        if (!root->left && !root->right) {
            vec.push_back(root->val);
            return;
        }
        if (root->left) {
            inOrder(root->left);
        }
        vec.push_back(root->val);
        if (root->right) {
            inOrder(root->right);
        }
    }
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }

    int next() {
        return vec[i++];
    }

    bool hasNext() {
        return i < vec.size();
    }
};