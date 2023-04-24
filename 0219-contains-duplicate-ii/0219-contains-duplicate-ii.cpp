
class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_set<int> window;
        for (int i = 0; i < n && i <= k; i++) {
            window.insert(nums.at(i));
        }
        if (window.size() != k+1 && window.size() != n) {
            return true;
        }

        for (int i = k+1; i < n; i++) {
            window.erase(nums.at(i-(k+1)));
            window.insert(nums.at(i));
            if (window.size() != k+1) {
                return true;
            }
        }
        return false;
    }
};