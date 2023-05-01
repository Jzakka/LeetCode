class Solution {
private:
    vector<int> nums;
    unordered_map<uint64_t , int> DP;
public:
    uint64_t hashFourInts(int a, int b, int c, int d) {
        return ((uint64_t)a << 48) | ((uint64_t)b << 32) | ((uint64_t)c << 16) | d;
    }

    int coin(int start, int end, int leftIdx, int rightIdx){
        int hashedInput = hashFourInts(start, end, leftIdx, rightIdx);
        if (DP.find(hashedInput) != DP.end()) {
            return DP[hashedInput];
        }
        int leftCoin = leftIdx < 0 ? 1 : nums.at(leftIdx);
        int rightCoin = rightIdx == nums.size() ? 1 : nums.at(rightIdx);

        if (start == end) {
            return 0;
        }

        int maxCoin = 0;
        for (int k = start; k < end; k++) {
            int gotCoin = 0;
            gotCoin += coin(start, k, leftIdx, k);
            gotCoin += leftCoin * nums.at(k) * rightCoin;
            gotCoin += coin(k + 1, end, k, rightIdx);
            maxCoin = max(maxCoin, gotCoin);
        }

        DP[hashedInput] = maxCoin;
        return maxCoin;
    }

    int maxCoins(vector<int> &nums) {
        this->nums = nums;

        return coin(0, nums.size(), -1, nums.size());
    }
};