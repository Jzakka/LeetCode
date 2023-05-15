class Solution {
public:
    map<pair<TreeNode*, bool>, int> DP;

    int rob(TreeNode *root) {
        return max(rob(root, true), rob(root, false));
    }

    int rob(TreeNode *node, bool prevRobbed) {
        if (DP.find({node, prevRobbed}) != DP.end()) {
            return DP[{node, prevRobbed}];
        }
        if (!node) {
            return 0;
        }
        if (!node->left && !node->right) {
            return prevRobbed ? 0 : node->val;
        }

        int cantRobCurrentHouseMoney = rob(node->left, false) + rob(node->right, false);
        if (prevRobbed) {
            DP[{node, prevRobbed}] = cantRobCurrentHouseMoney;
            return cantRobCurrentHouseMoney;
        }
        /*
         * 훔칠 수 있는 상황인데
         * 일부러 안 훔친거랑 훔친거랑 비교해서 더 큰 거를 고르는
         */
        int robbedCurrentHouseMoney = node->val + rob(node->left, true) + rob(node->right, true);
        DP[{node, prevRobbed}] = max(cantRobCurrentHouseMoney, robbedCurrentHouseMoney);
        return DP[{node, prevRobbed}];
    }
};