class Solution {
private:
    set<vector<int>> combinations;
    vector<vector<int>> result;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<int> temp;
        for (unsigned i = 0; i < candidates.size(); i++) {
            dfs(candidates, target, i, temp);
        }
        for (auto& v:combinations) {
            result.push_back(v);
        }
        return result;
    }

    void dfs(vector<int>& candidates, int sum, int current, vector<int> temp){
        sum -= candidates.at(current);
        temp.push_back(candidates.at(current));

        if (sum == 0){
            combinations.insert(temp);
            return;
        } else if (sum < 0) {
            return;
        }

        for (unsigned i = current+1; i < candidates.size(); i++) {
            dfs(candidates, sum, i, temp);
            while (i + 1 < candidates.size() && candidates.at(i) == candidates.at(i + 1)) {
                i++;
            }
        }
    }

    void clear(){
        combinations.clear();
        result.clear();
    }
};