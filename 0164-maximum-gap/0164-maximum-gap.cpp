class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        radixSort(nums, 0, 10);
        int maxGap = 0;

        for (int i = 1; i < n; i++) {
            maxGap = max(maxGap, abs(nums[i - 1] - nums[i]));
        }
        return maxGap;
    }

    void radixSort(vector<int>& nums, int e, const int n){
        for (; e <= n; e++) {
            vector<list<int>> buckets(10);
            for(auto & num:nums){
                int digit = num % (long)pow(10, e + 1) / pow(10, e);
                buckets[digit].push_back(num);
            }
            int i = 0;
            for(auto & bucket:buckets){
                for (auto num: bucket) {
                    nums[i++] = num;
                }
            }
        }
    }
};