class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        int achieveSum = len * (len + 1) / 2;
        int sum = 0;
        for (auto &num: nums) {
            sum += num;
        }
        return achieveSum - sum;
    }
};