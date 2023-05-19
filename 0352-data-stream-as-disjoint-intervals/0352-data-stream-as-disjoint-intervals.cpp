class SummaryRanges {
    vector<bool> nums; 
public:
    SummaryRanges() {
        nums = vector<bool>(1001);
    }

    void addNum(int value) {
        nums.at(value) = true;
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> res;

        for (int i = 0; i <= 1000; i++) {
            if (nums.at(i)) {
                vector<int> interval;
                interval.push_back(i);
                int j = i;
                for (; j <= 1000 && nums.at(j); j++);
                interval.push_back(j - 1);
                i = j;
                res.push_back(interval);
            }
        }

        return res;
    }
};