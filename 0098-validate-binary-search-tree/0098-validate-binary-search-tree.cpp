class Solution {
private:
    map<TreeNode *, long> maxMap;
    map<TreeNode *, long> minMap;
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        if (!isValidBST(root->left) || !isValidBST(root->right)) {
            return false;
        }
        long leftMax = findMax(root->left);
        long rightMin = findMin(root->right);
        return leftMax < root->val && root->val < rightMin;
    }

    long findMax(TreeNode* node){
        if(node == nullptr) return INT64_MIN;
        if (maxMap.find(node) != maxMap.end()) {
            return maxMap[node];
        }
        long left = findMax(node->left);
        long right = findMax(node->right);
        maxMap[node] = max((long)node->val, max(left, right));
        return maxMap[node];
    }

    long findMin(TreeNode* node){
        if(node == nullptr) return INT64_MAX;
        if (minMap.find(node) != minMap.end()) {
            return minMap[node];
        }
        long left = findMin(node->left);
        long right = findMin(node->right);
        minMap[node] = min((long)node->val, min(left, right));
        return minMap[node];
    }
};