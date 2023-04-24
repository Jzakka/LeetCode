class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        do{
            result.push_back(nums);
        } while (std::next_permutation(nums.begin(), nums.end()));

        return result;
    }
};