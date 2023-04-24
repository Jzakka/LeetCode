class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minVal = 20000;

        int maxProfit = -20000;
        for (int i = 0; i < prices.size(); i++) {
            minVal = min(minVal, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minVal);
        }

        return maxProfit <= 0 ? 0 : maxProfit;
    }
};