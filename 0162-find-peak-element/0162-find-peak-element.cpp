class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int s = 0;
        int e = nums.size() - 1;
        int n = e + 1;
        while (s < e) {
            int mid = (s + e) / 2;
            if (isPeak(nums, s, n)) {
                return s;
            } else if (isPeak(nums, e, n)) {
                return e;
            } else if (isPeak(nums, mid, n)) {
                return mid;
            }
            if (getNum(nums, mid, n) < getNum(nums, mid + 1, n)) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }
        return 0;
    }

    bool isPeak(vector<int> &nums, int idx, int size) {
        long left = getNum(nums, idx - 1, size);
        long num = getNum(nums, idx, size);
        long right = getNum(nums, idx + 1, size);
        return left < num && num > right;
    }

    long getNum(vector<int> &nums, int idx, int size) {
        if (idx == -1 || idx == size) return INT64_MIN;
        return nums[idx];
    }
};