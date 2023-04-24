class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<int> temp;
        vector<vector<int>> res;

        res.push_back({});
        for (auto it = nums.begin(); it != nums.end(); it++) {
            recursive(res,temp, it, nums);
        }
        return res;
    }

    void recursive(vector<vector<int>>& res, vector<int> &temp, vector<int>::iterator& it, vector<int>& nums) {
        temp.push_back(*it);
        res.push_back(temp);
        for (auto _it = it + 1; _it != nums.end(); _it++) {
            recursive(res, temp, _it, nums);
        }
        temp.pop_back();
    }
};