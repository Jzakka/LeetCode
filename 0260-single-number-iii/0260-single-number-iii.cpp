class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (auto &num: nums) {
            cnt[num]++;
        }
        vector<int> res;
        for (auto &p: cnt) {
            if (p.second == 1) {
                res.push_back(p.first);
            }
        }
        return res;
    }
};