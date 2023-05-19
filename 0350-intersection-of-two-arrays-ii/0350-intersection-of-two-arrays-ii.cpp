class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        vector<int> counts(1001);

        for (const auto &num: nums2) {
            counts.at(num)++;
        }

        for (const auto &num: nums1) {
            if (counts.at(num) > 0) {
                res.push_back(num);
                counts.at(num)--;
            }
        }
        
        return res;
    }
};