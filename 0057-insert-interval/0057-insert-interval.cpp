
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int start, end;
        start = newInterval.at(0);
        end = newInterval.at(1);
        vector<vector<int>> res;

        auto it = intervals.begin();
        while (it != intervals.end() && (*it).at(1) < newInterval.at(0)) {
            res.push_back((*it));
            it++;
        }

        if (it != intervals.end())
            start = min((*it).at(0), start);

        while (it != intervals.end() && (*it).at(0) <= newInterval.at(1)) {
            end = max((*it).at(1), end);
            it++;
        }

        res.push_back({start, end});

        while (it != intervals.end()) {
            res.push_back((*it));
            it++;
        }

        return res;
    }
};