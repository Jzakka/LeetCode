
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        for (int i = 0; i < k - 1; i++) {
            window.insert(nums.at(i));
        }

        vector<int> res;

        for (int start = 0, end = k-1; end < nums.size(); start++, end++) {
            window.insert(nums.at(end));
            int maxVal = *(prev(window.end()));
            res.push_back(maxVal);
            window.erase(window.find(nums.at(start)));
        }
        return res;
    }
};