class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        map<int, set<int>> orderedEnvelopes;

        for (const auto &envelope: envelopes) {
            orderedEnvelopes[envelope.front()].insert(envelope.back());
        }

        vector<int> vec;
        for (const auto &orderedEnvelope: orderedEnvelopes) {
            auto heights = orderedEnvelope.second;
            for (auto it = heights.rbegin(); it != heights.rend(); it++) {
                if (!vec.empty() && vec.back() >= *it) {
                    auto lb = std::lower_bound(vec.begin(), vec.end(), *it);
                    *lb = *it;
                } else {
                    vec.push_back(*it);
                }
            }
        }
        return vec.size();
    }
};