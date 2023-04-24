class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int sum = 0;
        vector<int> gain(gas.size());
        for (int i = 0; i < gain.size(); i++) {
            gain[i] = gas[i] - cost[i];
            sum += gain[i];
        }
        if (sum < 0) return -1;

        int start, acc, cursor;
        start = acc = cursor = 0;
        for (; cursor < gain.size(); cursor++) {
            acc += gain[cursor];
            if (acc < 0) {
                start = cursor + 1;
                acc = 0;
            }
        }

        return start;
    }
};