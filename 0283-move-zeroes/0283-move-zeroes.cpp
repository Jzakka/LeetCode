
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        for (auto &num: nums) {
            if (num) {
                nums[i++] = num;
            }
        }

        for (; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};