class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return inOrder(1, n);
    }

    vector<TreeNode *> inOrder(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        if (start == end) {
            return {new TreeNode(start)};
        }

        vector<TreeNode *> left, right, res;
        for (int i = start; i <= end; i++) {
            left = inOrder(start, i - 1);
            right = inOrder(i + 1, end);
            for (auto &l: left) {
                for (auto &r: right) {
                    res.push_back(new TreeNode(i, l, r));
                }
            }
        }
        return res;
    }
};