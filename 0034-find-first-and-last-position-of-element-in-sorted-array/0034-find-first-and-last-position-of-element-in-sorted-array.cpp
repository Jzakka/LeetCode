class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if(nums.empty()) return {-1, -1};
        int min = INT32_MAX;
        int max = INT32_MIN;

        // find min
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        while (l < r) {
            mid = (l + r) / 2;
            if (nums.at(mid) > target) {
                r = mid;
            } else {
                if (nums.at(mid) == target && mid > max) {
                    max = mid;
                }
                l = mid + 1;
            }
        }
        cout << "DEBUG"<<  l << " " << r << "\n";
        if (nums.at(r) == target && r > max) {
            max = r;
        }
        l = 0;
        r = nums.size() - 1;
        while (l < r) {
            if (nums.at(l) == target && l < min) {
                min = l;
            }
            mid = (l + r) / 2;
            if (nums.at(mid) >= target) {
                if (nums.at(mid) == target && mid < min) {
                    min = mid;
                }
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "DEBUG"<<  l << " " << r << "\n";
        if (nums.at(l) == target && l < min) {
            min = l;
        }
        if (min == INT32_MAX) return {-1, -1};
        return {min, max};
    }
};