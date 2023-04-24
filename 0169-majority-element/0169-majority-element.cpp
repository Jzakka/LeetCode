class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = -1;
        int cnt = 0;
        for (const auto &num: nums) {
            if (cnt == 0) {
                major = num;
                cnt = 1;
            } else if (major != num) {
                cnt--;
            } else {
                cnt++;
            }
        }
        return major;
    }
};