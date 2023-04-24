class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> check(100001, false);
        for (auto& num: nums) {
            if (num < 0 || 100000 < num) {
                continue;
            }
            check[num] = true;
        }
        for (unsigned i = 1; i <= 100000; i++) {
            if(!check[i]) return i;
        }
        return 100001;
    }
};