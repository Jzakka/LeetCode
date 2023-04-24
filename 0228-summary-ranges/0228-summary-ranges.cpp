class Solution {
public:
    vector<string> summaryRanges(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        vector<vector<int>> consecutives;
        consecutives.push_back({nums.front()});

        for (auto it = nums.begin() + 1; it != nums.end(); it++) {
            int prev = consecutives.back().back();
            if (prev + 1 == *it) {
                consecutives.back().push_back(*it);
            } else {
                consecutives.push_back({*it});
            }
        }

        vector<string> res;
        for (auto &consecutive: consecutives) {
            if (consecutive.size() == 1) {
                res.push_back(to_string(consecutive.front()));
            } else {
                string exp = to_string(consecutive.front())
                             + "->"
                             + to_string(consecutive.back());
                res.push_back(exp);
            }
        }
        return res;
    }
};