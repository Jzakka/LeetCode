class Solution {
public:
    int singleNumber(vector<int> &nums) {
        bitset<60001> set;
        set.reset();

        for (auto &num: nums) {
            set.flip(num + 30000);
        }

        for (int i = 0; i < 60001; i++) {
            if (set.test(i)) {
                return i-30000;
            }
        }
        return -1;
    }
};