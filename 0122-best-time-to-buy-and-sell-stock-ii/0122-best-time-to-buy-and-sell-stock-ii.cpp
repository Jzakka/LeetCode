class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minVal = prices[0];

        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (((i + 1 != prices.size() && prices[i] > prices[i + 1])
                 || (i + 1 == prices.size()))
                && i - 1 >= 0 && prices[i] >= prices[i - 1]) {
                int delta = prices[i] - minVal;
                if (delta > 0) {
                    maxProfit += delta;
                    minVal = prices[i];
                }
            } else if (i + 1 != prices.size() && prices[i] < prices[i + 1]
                       && i - 1 >= 0 && prices[i] <= prices[i - 1]) {
                if (minVal - prices[i] > 0) {
                    minVal = prices[i];
                }
            }

        }
        return maxProfit <= 0 ? 0 : maxProfit;
    }
};