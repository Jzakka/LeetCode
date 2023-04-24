class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        stack<TreeNode*> stk;
        unordered_set<TreeNode*> visited;
        stk.push(root);
        vector<int> res;
        res.push_back(root->val);
        while (!stk.empty()){
            auto node = stk.top();

            if (node->left != nullptr && visited.find(node->left) == visited.end()) {
                stk.push(node->left);
                res.push_back(stk.top()->val);
                visited.insert(node->left);
            }
            else if (node->right != nullptr && visited.find(node->right) == visited.end()) {
                stk.push(node->right);
                res.push_back(stk.top()->val);
                visited.insert(node->right);
            }else{
                stk.pop();
            }
        }
        return res;
    }
};