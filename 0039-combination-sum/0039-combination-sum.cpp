class Solution {
private:
    vector<vector<int>> combinations;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>::iterator it;
        for (it = candidates.begin(); it != candidates.end(); it++) {
            int sum = 0;
            vector<int> combination;
            recursive(it, sum, combination, candidates, target);
        }
        return combinations;
    }

    void recursive(vector<int>::iterator it, int sum, vector<int>combination, vector<int>& candidates, int target){
        int num = *it;
        sum += num;
        combination.push_back(num);
        if (sum == target) {
            combinations.emplace_back(combination);
            return;
        } else if (sum > target) {
            return;
        }
        for (auto _it = it; _it != candidates.end(); _it++) {
            recursive(_it, sum, combination, candidates, target);
        }
    }
};