class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {

        std::sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a.at(0) < b.at(0);
        });

        int start = intervals.at(0).at(0);
        int end = intervals.at(0).at(1);
        vector<vector<int>> res;

        auto it = intervals.begin() + 1;
        while (it != intervals.end()) {
            if (end >= (*it).at(0)) {
                end = max(end,(*it).at(1));
            }
            else{
                res.push_back({start, end});
                start = (*it).at(0);
                end = (*it).at(1);
            }
            it++;
        }
        res.push_back({start, end});
        return res;
    }
};
