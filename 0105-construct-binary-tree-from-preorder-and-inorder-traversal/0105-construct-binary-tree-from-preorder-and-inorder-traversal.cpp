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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inOrderIdx;
        map<int,int> found;
        unordered_map<int, TreeNode*> numberNode;
        for (int i = 0; i< inorder.size(); i++) {
            inOrderIdx[inorder[i]] = i;
        }
        TreeNode *root = new TreeNode(preorder[0]);
        numberNode[root->val] = root;
        found[inOrderIdx[root->val]] = root->val;
        for (int i = 1; i < preorder.size(); i++) {
            auto prevNum = preorder[i-1];
            auto curNum = preorder[i];
            auto curNode = new TreeNode(curNum);
            numberNode[curNum] = curNode;
            found[inOrderIdx[curNum]] = curNum;
            if (inOrderIdx[curNum] < inOrderIdx[prevNum]) {
                numberNode[prevNum]->left = curNode;
            } else {
                numberNode[prev(found.find(inOrderIdx[curNum]))->second]->right = curNode;
            }
        }
        return root;
    }
};