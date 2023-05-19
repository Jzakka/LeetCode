class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> res;
        unordered_set<int> set(nums2.begin(), nums2.end());

        for (const auto &num: nums1){
            if (set.find(num) != set.end()) {
                res.insert(num);
            }
        }

        return vector<int>(res.begin(), res.end());
    }
};