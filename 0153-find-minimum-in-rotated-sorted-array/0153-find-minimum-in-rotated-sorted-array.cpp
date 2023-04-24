class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;
        while (nums[s] > nums[e]) {
            int m = (s + e) / 2;
            if (nums[s] > nums[m]) {
                e = m;
            }
            else if (nums[m] >= nums[e]) {
                s = m + 1;
            }
        }

        return nums[s];
    }
};