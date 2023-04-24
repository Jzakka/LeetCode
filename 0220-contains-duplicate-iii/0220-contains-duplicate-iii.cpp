
class Solution {
private:
    struct Compare {
        bool operator()(int a, int b) const {
            return a < b;
        }
    };

public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        int len = nums.size();
        multiset<int, Compare> window;

        for (int i = 0; i < len; i++) {
            if (i - indexDiff - 1 >= 0) {
                window.erase(nums.at(i - indexDiff - 1));
            }

            int num = nums.at(i);
            window.insert(num);
            auto it = window.find(num);
            if (it != window.begin()) {
                if (abs((*prev(it)) - num) <= valueDiff) {
                    return true;
                }
            }
            if (next(it) != window.end()) {
                if (abs((*next(it)) - num) <= valueDiff) {
                    return true;
                }
            }
        }
        return false;
    }
};