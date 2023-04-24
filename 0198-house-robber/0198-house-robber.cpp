class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n, INT32_MIN);
        int profit1 = recursive(DP,nums, 0, n, 0);
        int profit2 = recursive(DP,nums, 1, n, 0);
        return max(profit1, profit2);
    }

    int recursive(vector<int> &DP, vector<int> &nums, int pos, int len, int profit) {
        if (pos >= len) {
            return profit;
        }
        profit += nums.at(pos);
        if (profit <= DP.at(pos)) {
            return DP.at(pos);
        }
        DP.at(pos) = profit;
        int maxVal = profit;
        for (int i = pos + 2; i <= len; i++) {
            maxVal = max(recursive(DP, nums, i, len, profit), maxVal);
        }
        return maxVal;
    }
};