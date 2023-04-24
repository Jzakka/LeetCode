class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> release(k, 0);
        vector<int> hold(k, INT32_MIN);
        for (auto &price: prices) {
            for (int i = k - 1; i >= 0; i--) {
                release[i] = max(release[i], hold[i] + price);
                hold[i] = max(hold[i], i ? release[i - 1] - price : -price);
            }
        }
        return release[k - 1];
    }
};