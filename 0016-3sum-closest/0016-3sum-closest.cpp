class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int res;
        int dist = INT32_MAX;
        auto fix = nums.begin();

        for (; fix != nums.end(); fix++) {
            auto l = next(fix);
            auto r = prev(nums.end());

            while (l < r) {
                int _dist = abs(*fix + *l + *r - target);
                if(_dist<dist) {
                    dist = _dist;
                    res = *fix + *l + *r ;
                }

                if(*fix + *l + *r < target) l++;
                else if(*fix + *l + *r > target) r--;
                else return target;
            }
        }
        return res;
    }
};