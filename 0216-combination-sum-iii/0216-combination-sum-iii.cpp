
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        for (int i = 1; i <= 9; i++) {
            vector<int> combination(k, 0);
            build(result, combination, i, k, 0, n);
        }
        return result;
    }

    void build(vector<vector<int>> &result, vector<int> &combination, int start, int k, int idx, int remain) {
        remain -= start;
        if (remain < 0 || idx == k || (idx == k - 1 && remain != 0)) {
            return;
        }
        combination.at(idx) = start;
        if (idx == k - 1) {
            result.push_back(combination);
        }
        for (int i = start + 1; i <= 9; i++) {
            build(result, combination, i, k, idx + 1, remain);
        }
        combination.at(idx) = 0;
    }
};