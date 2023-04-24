
class Solution {
private:
    set<vector<int>> subSets;
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        std::sort(nums.begin(), nums.end());
        vector<int> subset = {};
        subSets.insert(subset);
        recursive(nums, 0, subset);
        return vector<vector<int>>(subSets.begin(), subSets.end());
    }

    void recursive(vector<int> &nums, int idx, vector<int>& subset){
        if (idx == nums.size()) {
            return;
        }

        subset.push_back(nums[idx]);
        if (subSets.find(subset) == subSets.end()) {
            subSets.insert(subset);
        }
        recursive(nums, idx + 1, subset);
        subset.pop_back();
        recursive(nums, idx + 1, subset);
    }
};
