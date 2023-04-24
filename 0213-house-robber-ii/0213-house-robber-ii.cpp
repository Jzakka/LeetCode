
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> DP(n, INT32_MIN);
        vector<int> DP2(n, INT32_MIN);
        if(n==1){
            return nums.at(0);
        }
        int profit1 = recursive(DP,nums, 0, n-1, 0);
        int profit2 = recursive(DP2, nums, 1, n, 0);
        int profit3 = recursive(DP2,nums, 2, n, 0);
        return max(profit1, max(profit2, profit3));
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