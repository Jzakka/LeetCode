class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        for (auto first = nums.begin(); first != nums.end(); first++) {
            for (auto second = next(first); second != nums.end(); second++) {
                auto l = next(second);
                auto r = prev(nums.end());

                while (l < r) {
                    long quad = (long)*first + *second + *l + *r;

                    if (quad == (long)target) {
                        result.insert(vector<int>{*first, *second, *l, *r});
                        l++;
                        r--;
                    } else if (quad < (long)target) l++;
                    else r--;
                }
            }
        }
        vector<vector<int>> vecRes;
        std::for_each(result.begin(), result.end(), [&vecRes](vector<int> vec) {
            vecRes.push_back(vec);
        });
        return vecRes;
    }
};