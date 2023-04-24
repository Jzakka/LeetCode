class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int sz = nums.size();
        if (sz == 1) return;

        for (int i = sz - 1; i >= 0; i--) {
            int leastBigger = 101;
            int idx;
            for (int j = i +1; j < sz; j++) {
                if (nums[i] < nums[j] && nums[j] < leastBigger) {
                    leastBigger = nums[j];
                    idx = j;
                }
            }
            if (leastBigger != 101) {
                swap(nums[i], nums[idx]);
                sort(nums.begin() + i + 1, nums.end(), [](int a, int b) {
                    return a < b;
                });
                return;
            }
        }
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
    }
};