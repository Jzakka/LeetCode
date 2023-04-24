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
public:
    int countNodes(TreeNode *root) {
        int cnt = 0;

        queue<TreeNode *> queue;
        if(root)
            queue.push(root);
        while (!queue.empty()){
            auto node = queue.front();
            queue.pop();
            
            if(node->left) queue.push(node->left);
            if(node->right) queue.push(node->right);

            cnt++;
        }
        
        return cnt;
    }
};