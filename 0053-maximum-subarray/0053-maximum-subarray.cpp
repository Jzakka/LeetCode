class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sums[len];
        int minSumArr[len + 1];
        unordered_map<int,int> map;
        map[0] = 0;
        minSumArr[0] = 0;
        int minSum = 0;
        int sum = 0;
        for (int i = 0; i < len; i++) {
            sum += nums.at(i);
            sums[i] = sum;
            if(sum < minSum){
                map[sum] = i;
                minSum = sum;
            }
            minSumArr[i + 1] = minSum;
        }

        int maxSum = INT32_MIN;
        for (int i = 0; i < len; i++) {
            int subMaxSum = sums[i] - minSumArr[i];
            maxSum = max(subMaxSum, maxSum);
        }

        return maxSum;
    }
};
