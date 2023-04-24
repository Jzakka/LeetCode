
class Solution {
private:
    set<int> sequence;
public:
    int kthSmallest(TreeNode *root, int k) {
        traversal(root);
        int cnt = 1;
        auto it = sequence.begin();
        for (; it != sequence.end() && cnt < k; it = next(it), cnt++);
        return *it;
    }
    void traversal(TreeNode* node){
        if (node->left) {
            traversal(node->left);
        }
        sequence.insert(node->val);
        if (node->right) {
            traversal(node->right);
        }
    }
};