
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l,r,m;
        r = nums.size();
        l = 0;

        while (m = (l + r) / 2, l < r){
            if (nums.at(m) > target) {
                r = m;
            } else if(nums.at(m) < target) {
                l = m + 1;
            }else
                return m;
        }

        return m;
    }
};