class Solution {
private:
    stack<TreeNode *> leftStack;
    stack<TreeNode *> rightStack;
    map<TreeNode *, bool> visited;
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *leftNode = root->left;
        TreeNode *rightNode = root->right;
        visited[nullptr] = true;
        if (leftNode == nullptr ^ rightNode == nullptr) {
            return false;
        } else if (leftNode == nullptr && rightNode == nullptr) {
            return true;
        }
        leftStack.push(root);
        rightStack.push(root);
        do {
            // 처리
            visited[leftNode] = true;
            visited[rightNode] = true;
            if (leftNode->val != rightNode->val) {
                return false;
            }

            // 다음에 갈 곳 찾기
            if (leftNode->right == nullptr ^ rightNode->left == nullptr) {
                return false;
            } else if (leftNode->left == nullptr ^ rightNode->right == nullptr) {
                return false;
            }
            if (!visited[leftNode->right] && !visited[rightNode->left]) {
                leftStack.push(leftNode);
                rightStack.push(rightNode);
                leftNode = leftNode->right;
                rightNode = rightNode->left;
                continue;
            } else if (!visited[leftNode->left] && !visited[rightNode->right]) {
                leftStack.push(leftNode);
                rightStack.push(rightNode);
                leftNode = leftNode->left;
                rightNode = rightNode->right;
                continue;
            }

            leftNode = leftStack.top();
            leftStack.pop();
            rightNode = rightStack.top();
            rightStack.pop();
        } while (!leftStack.empty() && !rightStack.empty());

        return true;
    }
};