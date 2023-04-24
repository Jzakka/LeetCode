class NumArray {
private:
    vector<int> accSum;
    map<int, int> updateLog;
public:
    NumArray(vector<int> &nums) {
        accSum = vector<int>(nums.size(), 0);
        int sum = 0;
        int idx = 0;
        for (int num: nums) {
            sum += num;
            accSum.at(idx++) = sum;
        }
    }

    void update(int index, int val) {
        if (updateLog.size() == 30) {
            int delta = 0;
            auto it = updateLog.begin();
            for (; it != updateLog.end(); it++) {
                int i = it->first;
                delta += it->second;
                while ((next(it) != updateLog.end() && i < next(it)->first)
                       || (next(it)==updateLog.end() && i< accSum.size())) {
                    accSum.at(i++) += delta;
                }
            }
            updateLog.clear();
        }
        int originVal = accSum.at(index) - (index == 0 ? 0 : accSum.at(index - 1));
        updateLog[index] = val - originVal;
    }

    int sumRange(int left, int right) {
        int delta = 0;
        for (auto entry: updateLog) {
            if (left <= entry.first && entry.first <= right) {
                delta += entry.second;
            }
        }
        return accSum.at(right) - (left == 0 ? 0 : accSum.at(left - 1)) + delta;
    }
};