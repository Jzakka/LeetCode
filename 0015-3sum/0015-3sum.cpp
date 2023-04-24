class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> temp;

        for (auto fix = nums.begin(); fix != nums.end(); fix++) {
            auto s = next(fix);
            auto e = prev(nums.end());

            while (s < e) {
                if (s == fix) {
                    s++;
                    continue;
                }
                if (e == fix) {
                    e--;
                    continue;
                }

                if (*s + *e + *fix< 0) {
                    s++;
                } else if (*s + *e + *fix == 0) {
                    temp.insert(vector<int>{*fix, *s, *e});
                    s++;
                    e--;
                } else {
                    e--;
                }
            }
        }

        vector<vector<int>> result;
        for_each(temp.begin(), temp.end(), [&result](vector<int> s) {
            result.push_back(s);
        });

        return result;
    }
};