class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        } else if (prices.size() == 2) {
            return max(0, prices.at(1) - prices.at(0));
        }

        int hold = INT32_MIN;
        int prevRelease = 0;
        int release = 0;
        int coolDown = 0;

        for (auto &price: prices) {
            release = max(release, hold + price);
            hold = max(hold, coolDown - price);
            coolDown = prevRelease;
            prevRelease = release;
        }

        return release;
    }
};