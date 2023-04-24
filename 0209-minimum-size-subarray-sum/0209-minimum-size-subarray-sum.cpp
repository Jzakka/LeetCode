
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int acc = 0;
        int minIdx = 0;
        int minLen = INT32_MAX;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            acc += nums.at(i);
            while (acc - nums.at(minIdx) >= target) {
                acc -= nums.at(minIdx++);
            }
            if (acc >= target) {
                minLen = min(minLen, i - minIdx + 1);
            }
        }
        return minLen == INT32_MAX ? 0:minLen;
    }
};