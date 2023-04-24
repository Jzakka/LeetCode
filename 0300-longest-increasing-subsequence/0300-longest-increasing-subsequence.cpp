class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> vec;

        for (auto &num: nums) {
            if(!vec.empty() &&vec.back() >= num) {
                auto it = std::lower_bound(vec.begin(), vec.end(), num);
                *it = num;
            }else {
                vec.push_back(num);
            }
        }
        return vec.size();
    }
};